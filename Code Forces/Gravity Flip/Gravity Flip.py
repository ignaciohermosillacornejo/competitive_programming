# Problem: https://codeforces.com/contest/405/problem/A
# Tags: Implementation
# Status: Accepted

N = int(input())
l = sorted([int(x) for x in input().split(" ")])
l = [str(x) for x in l]
print(' '.join(l))
