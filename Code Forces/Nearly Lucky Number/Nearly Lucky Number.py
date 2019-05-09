# Problem: https://codeforces.com/problemset/problem/110/A
# Tags: Implementation
# Status: Accepted

def lucky_number(number):
    for d in number:
        if (d != '7' and d != '4'):
            return "NO"
        return "YES"


def count_lucky(number):
    count = 0
    for d in number:
        if (d == '7' or d == '4'):
            count += 1
    return lucky_number(str(count))


number = input()
print(count_lucky(number))
