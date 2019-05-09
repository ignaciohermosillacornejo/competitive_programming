# Problem: https://codeforces.com/problemset/problem/318/A
# Tags: Implementation, Math
# Status: Accepted

import math
n, k = input().split(" ")
n = int(n)
k = int(k)
# number of odd numbers in the array. If n is odd then z is odd
z = math.ceil(n/2)
if (k <= z):  # check to see if the number is odd
    print(2 * k - 1)
else:  # else the number is even
    print(2 * (k - z))
