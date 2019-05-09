# Problem: https://codeforces.com/contest/282/problem/A
# Tags: Implementation
# Status: Accepted


N = int(input())
X = 0
while (N != 0):
    N -= 1
    instruction = input()
    if (instruction == 'X++' or instruction == '++X'):
        X += 1
    else:
        X -= 1
print(X)
