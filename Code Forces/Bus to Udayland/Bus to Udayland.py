# Problem: https://codeforces.com/problemset/problem/711/A
# Tags: Brute Force, Implementation
# Status: Accepted

n = int(input())
bus = []
for i in range(n):
    bus.append(list(input()))


def print_bus(bus):
    print("YES")
    for row in bus:
        print("".join(row))


aux = True

for row in bus:
    if aux:
        if (row[0] == 'O' and row[1] == 'O'):
            row[0] = '+'
            row[1] = '+'
            aux = False
        elif (row[3] == 'O' and row[4] == 'O'):
            row[3] = '+'
            row[4] = '+'
            aux = False


if (aux):
    print("NO")
else:
    print_bus(bus)


