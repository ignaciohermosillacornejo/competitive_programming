M, N = input().split(" ")
N = int(N)
M = int(M)

def counter(m, n):
    if (m == 1 and n == 1):
        return 0
    if (m == 1 and n % 2 == 0):
        return int(n/2)
    if (m == 1 and n % 2 == 1):
        return int((n - 1)/ 2)
    if (m % 2 == 0 and n % 2 == 0):
        return int((m * n)/2)
    if (m % 2 == 0 and n % 2 == 1):
        return int((m * (n - 1))/2) + counter(1, m)
    if (m % 2 == 1):
        return counter(1, n) + int(((m - 1) * n)/2)

print(counter(M, N))
