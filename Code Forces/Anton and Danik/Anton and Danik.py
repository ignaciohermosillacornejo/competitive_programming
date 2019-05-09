# Problem: https://codeforces.com/problemset/problem/734/A
# Tags: Implementation
# Status: Accepted

n_games = int(input())
string = input()
anton = 0
danik = 0
for i in range(n_games):
    if (string[i] == "A"):
        anton += 1
    else:
        danik += 1
if (anton > danik):
    print("Anton")
elif (danik > anton):
    print("Danik")
else:
    print("Friendship")
