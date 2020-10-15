// Problem link: https://csacademy.com/ieeextreme-practice/task/concentration-game/
// By: Osama Khallouf

// IT IS NOT RECOMMENDED TO SOLVE THIS PROBLEM USING C++.
// Try Python or JavaScript for easier JSON parsing.

#include <bits/stdc++.h>
using namespace std;

string jsonLine;
bool firstOne = 1;

struct publication {
	int publicationNumber = 0;
	string publicationTitle = "";
	vector<int> years;
	int articleCount = 0;
	int citationCount = 0;
	double impactFactor = 0.0;
};

vector<publication> allPublications;

void parsePublications() {
	publication currentPublication;
	for (int i = 0; i < jsonLine.length(); i++) {
		if (jsonLine[i] == 'p') {
			string t = jsonLine.substr(i, 11);
			if (t != "publication") {
			    continue;
			}
			
			// "publicationTitle": "Letters on IEEEXtreme"
			// 0123456789012345678
			string s = jsonLine.substr(i+11, 6);
			if (s == "Title\"") {
				int j = i + 18;
				while (jsonLine[j++] != '\"');
				
				string title = "";
				while (jsonLine[j] != '\"') {
					title = title + jsonLine[j++];
				}
				
				i = j;
				if (!currentPublication.publicationTitle.empty()) {
					allPublications.push_back(currentPublication);
					currentPublication.articleCount = 0;
					currentPublication.years.clear();
				}
				currentPublication.publicationTitle = title;
			}
			
			else if (s == "Number") {
				// "publicationNumber": "1"
				// 01234567890123456789
				int j = i + 19;
				while (jsonLine[j++] != '\"');
				
				string number = "";
				while (jsonLine[j] != '\"') {
					number = number + jsonLine[j++];
				}
				i = j;
				currentPublication.publicationNumber = stoi(number);
			}
		}
		
		else if (jsonLine[i] == 'y') {
			// "year": "2017"
			// 0123456
			string s = jsonLine.substr(i, 4);
			if (s == "year") {
				int j = i + 6;
				while (jsonLine[j++] != '\"');
				
				string number = "";
				while (jsonLine[j] != '\"') {
					number = number + jsonLine[j++];
				}
				i = j;
				currentPublication.years.push_back(stoi(number));
			}
		}
		else if (jsonLine[i] == 'a') {
			// "articleCount": "3"
			// 012345678901234
			string s = jsonLine.substr(i, 13);
			if (s == "articleCount\"") {
				int j = i + 14;
				while (jsonLine[j++] != '\"');
				
				string number = "";
				while (jsonLine[j] != '\"') {
					number = number + jsonLine[j++];
				}
				i = j;
				currentPublication.articleCount += stoi(number);
			}
		}
	}
	allPublications.push_back(currentPublication);
}

void splitString(vector<pair<int, int>> &ans, string &s, char startChar, char endChar, int startIndex, int endIndex) {
	string last = "";
	ans.reserve(2000);
	
	pair<int, int> p = {-1,-1};
	for (int i = startIndex; i < endIndex; i++) {
		char &ch = s[i];
		if (ch == startChar) {
			p.first = i;
		}
		else if (ch == endChar) {
			p.second = i;
			ans.emplace_back(p);
			p = {-1,-1};
		}
	}
	if (p.first != -1) {
		if (p.second == -1) {
			p.second = endIndex - 1;
		}
		ans.emplace_back(p);
	}
}

inline void parsing() {
	if (firstOne) {
		parsePublications();
		firstOne = 0;
		return;
	}
	
	vector<pair<int, int>> v, citations;
	string &s = jsonLine;
	
	splitString(v, s, '[', ']', 0, s.length());
	splitString(citations, s, '{', '}', v[0].first, v[0].second);
	
	for (auto &pr : citations) {
		int publicationNumber = -1, year = -1;
		
		for (int i = pr.first; i < pr.second; i++) {
			if (s[i] == 'p') {
				// "publicationNumber": "4"
				// 01234567890123456789
				string t = s.substr(i, 17);
				if (t == "publicationNumber") {
					int j = i + 19;
					while (s[j++] != '\"');
					
					string number = "";
					while (s[j] != '\"') {
						number = number + s[j++];
					}
					
					publicationNumber = stoi(number);
					i = j;
				}
			}
			
			else if (s[i] == 'y') {
				// "year": "2018"
				// 0123456
				string t = s.substr(i, 4);
				if (t == "year") {
					int j = i + 6;
					while (s[j++] != '\"');
					
					string number = "";
					while (s[j] != '\"') {
						number = number + s[j++];
					}
					year = stoi(number);
					i = j;
				}
			}
        }
		
		for (auto &p : allPublications) {
			if (p.publicationNumber == publicationNumber) {
				for (int y : p.years) {
					if (y == year) {
					    p.citationCount++;
					}
				}
			}
		}
		
	}
}

bool comp(publication &a, publication &b) {
	if (abs(a.impactFactor - b.impactFactor) >= 0.01) {
		return a.impactFactor < b.impactFactor;
	}
	return a.publicationTitle > b.publicationTitle;
}

inline void printResults() {
	sort(allPublications.rbegin(), allPublications.rend(), comp);
	for (auto &p : allPublications) {
		printf("%s: %.2lf\n", p.publicationTitle.c_str(), p.impactFactor);
	}
}

inline void calculateIF() {
	for (auto &p : allPublications) {
		p.impactFactor = 1.0*p.citationCount / p.articleCount;
	}
}

int main() {
	int n;
	string str;
	
	cin >> n;
	getline(cin, str);
	
	allPublications.reserve(1000);
	
	int c = 0;
	jsonLine = "";
	while (getline(cin, str)) {
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
	
	calculateIF();
	printResults();
	return 0;
}
