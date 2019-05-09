# Problem: https://codeforces.com/contest/344/problem/A
# Tags: Implementation
# Status: Accepted

n_magnets = int(input())
count = 0
last_magnet = ""
for i in range(n_magnets):
    magnet = input()
    if (last_magnet != magnet):
        count = count + 1
        last_magnet = magnet
print(count)
