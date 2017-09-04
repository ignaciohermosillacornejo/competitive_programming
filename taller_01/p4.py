import re
from collections import Counter

def my_split(s):
    return filter(None, re.split(r'(\d+)', s))

string = input()
ls = list(my_split(string))
cnt = [Counter(list(((int(y)%3) for y in x))) for x in ls if x.isdigit() ]
total = 0
for item in cnt:
    total += item[0] +item[0]*(item[0] - 1)/2
    total += item[1]*(item[1] - 1)/2
    total += item[2]*(item[2] - 1)/2
print(int(total))
