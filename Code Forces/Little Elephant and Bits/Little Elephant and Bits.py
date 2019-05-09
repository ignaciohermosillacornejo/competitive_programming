# Problem: https://codeforces.com/contest/258/problem/A
# Tags: Math, Greedy
# Status: Accepted

a = list(input())

if ("0" in a):
    a.remove("0")
else:
    a.remove("1")

output = ""
for i in a:
    output += i
print(output)
