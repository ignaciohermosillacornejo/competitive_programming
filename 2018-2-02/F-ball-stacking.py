import sys
sys.setrecursionlimit(3000)

balls = [[]]
dp = [[]]
n = 0
accum = [[]]


def max_pyramid_i():
    for col in range(n - 1, -1, -1):
        for row in range(col, n):
            dp_i[row][col] = 0
            if (row == n - 1 and col == n - 1): # caso base
                dp_i[row][col] = max(accum[row][col], dp_i[row][col])
                continue

            if (row > col): # no estamos en la diagonal
                dp_i[row][col] = max(dp_i[row][col], dp_i[row - 1][col])

            score = accum[row][col] + dp_i[min(n - 1, row + 1)][col + 1]

            dp_i[row][col] = max(dp_i[row][col], score)
            # print_triangle(dp)
            # print_triangle(accum)
    return dp_i[n - 1][0]


def max_pyramid_r(row, col):

    if (dp_r[row][col] != -1):
        return dp_r[row][col]

    dp_r[row][col] = 0

    # base case(bottom right of the pyramid)
    if (row == n - 1 and col == n - 1):
        dp_r[row][col] = max(accum[row][col], dp_r[row][col])
        return dp_r[row][col]

    # we ask the question to the ball above it, when we are not in the diagonal
    if (row > col):
        dp_r[row][col] = max(dp_r[row][col], max_pyramid_r(row - 1, col))

    # we choose to take the ball and ask the new pyramid to the right
    # unless we are at the right-most diagonal
    score = accum[row][col] + max_pyramid_r(min(n-1, row + 1), col + 1)

    dp_r[row][col] = max(dp_r[row][col], score)
    return dp_r[row][col]


while(True):
    n = int(input())
    if (n == 0): break
    balls = [[0 for _ in range(n)] for _ in range(n)]
    dp_r  = [[-1 for _ in range(n)] for _ in range(n)]
    dp_i  = [[0 for _ in range(n)] for _ in range(n)]
    accum = [[0 for _ in range(n)] for _ in range(n)]

    for row in range(n):
        for col, number in enumerate([int(i) for i in input().split()]):
            balls[row][col] = number
            accum[row][col] = balls[row][col] + accum[max(0, row - 1)][col]

    #print(max_pyramid_i())
    print(max_pyramid_r(n - 1, 0))
