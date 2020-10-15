// Problem link: https://csacademy.com/ieeextreme-practice/task/xplore/
// By: Osama Khallouf

// IT IS NOT RECOMMENDED TO SOLVE THIS PROBLEM USING C++.
// Try Python or JavaScript for easier JSON parsing.

#include <bits/stdc++.h>
using namespace std;

struct author {
	int hIndex;
	int authorNumber;
	string name;
	vector<int> articlesIndicies;
} emptyAuthor;

struct article {
	long long citationNumber;
	int articleIndex;
	vector<int> authorsNumbers;
} emptyArticle;

int n, lastAuthor, last_idx;
string jsonLine;

vector<author> allAuthors = { emptyAuthor };
vector<article> allArticles = { emptyArticle };

map<string, int> name2int;
map<int, int> num2index;

vector<int> findAuthorsNumbers(int currentArticleIndex) {
	vector<int> articleAuthorsNumbers;
	int len = jsonLine.length();
	// "full_name": "Name"
	// "012345678901234567
	for (int i = 0; i < len - 10; i++) {
		if (jsonLine[i] != 'f') continue;
		string findString = jsonLine.substr(i, 9);
		
		if (findString == "full_name") {
			int j = i + 10;
			while (jsonLine[j++] != '\"');
			
			string newName;
			while (jsonLine[j] != '\"') {
				newName = newName + jsonLine[j++];
			}
			
			if (!name2int[newName]) {
				name2int[newName] = ++lastAuthor;
				author newAuthor;
				newAuthor.name = newName;
				newAuthor.authorNumber = lastAuthor;
				newAuthor.articlesIndicies.push_back(currentArticleIndex);
				allAuthors.push_back(newAuthor);
				articleAuthorsNumbers.push_back(newAuthor.authorNumber);
			}
			else {
				author &newAuthor = allAuthors[name2int[newName]];
				newAuthor.articlesIndicies.push_back(currentArticleIndex);
				articleAuthorsNumbers.push_back(newAuthor.authorNumber);
			}
		}
	}
	return articleAuthorsNumbers;
}

long long findCitationNumber() {
	int len = jsonLine.length();
	// "citing_paper_count": 10
	// 01234567890123456789012
	for (int i = 0; i < len - 19; i++) {
		if (jsonLine[i] != 'c') continue;
		string findString = jsonLine.substr(i, 18);
		
		if ((findString.compare("citing_paper_count")) == 0) {
			int j = i + 19;
			while (jsonLine[j] < '0' || jsonLine[j] > '9') {
				j++;
			}
			
			string stringNumber;
			long long intNumber;
			while (jsonLine[j] >= '0' && jsonLine[j] <= '9') {
				stringNumber = stringNumber + jsonLine[j++];
			}
			
			intNumber = stoll(stringNumber);
			return intNumber;
		}
	}
	return -1;
}

void parsing() {
	article newArticle;
	newArticle.articleIndex = allArticles.size();
	newArticle.citationNumber = findCitationNumber();
	newArticle.authorsNumbers = findAuthorsNumbers(newArticle.articleIndex);
	allArticles.push_back(newArticle);
}

bool sortAuthors(author &a, author &b) {
	if (a.hIndex != b.hIndex) {
	    return (a.hIndex > b.hIndex);
	}
	return (a.name < b.name);
}

bool check(long long h_index, vector<long long> &citations) {
	int sz = citations.size();
	long long c = 0;
	for (int i = sz - 1; i >= 0; i--) {
		if (citations[i] >= h_index) {
			c++;
		}
		else {
		    break;
		}
	}
	return (c >= h_index);
}

int find_h_index(author &currentAuthor) {
	int h_index = 0;
	vector<int> &articleIdx = currentAuthor.articlesIndicies;
	vector<long long> citations;
	for (int idx : articleIdx) {
		citations.push_back(allArticles[idx].citationNumber);
	}
	
	sort(citations.begin(), citations.end());
	long long l = 0, r = citations.size();
	
	while (l <= r) {
		long long mid = (r + l) >> 1;
		if (check(mid, citations)) {
			h_index = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return h_index;
}

void findAllIndex() {
	for (int i = 1; i <= lastAuthor; i++) {
		author &currentAuthor = allAuthors[i];
		currentAuthor.hIndex = find_h_index(currentAuthor);
	}
	sort(allAuthors.begin() + 1, allAuthors.end(), sortAuthors);
}

void printResults() {
	for (int i = 1; i < (int)allAuthors.size(); i++) {
        cout << allAuthors[i].name << ' ' << allAuthors[i].hIndex << '\n';
	}
}

int main() {
	int n;
	cin >> n;
	int c = 0;
	string str;
	jsonLine = "";
	while (cin >> str) {
		int len = str.length();
		for (int i = 0; i < len; i++) {
			c += str[i] == '{';
			c -= str[i] == '}';
			jsonLine = jsonLine + str[i];
			if (c == 0) {
				parsing();
				jsonLine = "";
			}
		}
	}
	findAllIndex();
	printResults();
	return 0;
}
