# Problem: https://codeforces.com/problemset/problem/141/A
# Tags: Implementation, Sorting, Strings
# Status: Accepted

from collections import Counter
guest1 = Counter(list(input()))
guest2 = Counter(list(input()))
pile = Counter(list(input()))
if (guest1 + guest2 == pile):
    print("YES")
else:
    print("NO")
