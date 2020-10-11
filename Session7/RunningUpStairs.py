// Problem link: https://csacademy.com/ieeextreme-practice/task/96c8b1313edd72abf600facb0a14dbab/
// By: Osama Khallouf

# =============== Starting of the automated code =========================

# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# numpy and scipy are available for use
import numpy
import scipy

'''
a = get_number()
b = get_number()

res = a + b
print(res)
'''

# =============== Ending of the automated code =========================


N = 22005
ans = [0 for i in range(N)]

ans[0] = 1
ans[1] = 1

for i in range(2,N):
    ans[i] = ans[i-1] + ans[i-2]

t = get_number()
for i in range(t):
    n = get_number()
    print(ans[n])
    
    
