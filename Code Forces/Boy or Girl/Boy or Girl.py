# Problem: https://codeforces.com/contest/236/problem/A
# Tags: Implementation
# Status: Accepted

from collections import Counter
user_name = Counter(list(input()))
if (len(user_name) % 2 == 0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
