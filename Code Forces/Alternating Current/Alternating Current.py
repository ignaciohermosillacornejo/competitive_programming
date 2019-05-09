# Problem: https://codeforces.com/problemset/problem/343/B
# Tags: Implementation
# Status: Accepted

wires = input()
c = 0
d = 0
for i in range(len(wires)):
    if (wires[i] == '+'):
        c += 2*(i % 2) - 1
    if (wires[i] == '-'):
        d += 2*(i % 2) - 1
if c == 0 and d == 0:
    print("Yes")
else:
    print("No")
