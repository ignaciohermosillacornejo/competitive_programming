N, T = input().split(" ")
N = int(N)
T = int(T)
queue = list(input())
while (T != 0):
    next_queue = [None] * N
    for i in range(N):
        if (i == N - 1 and next_queue[N - 1] is None):
            next_queue[N - 1] = queue[N - 1]
            break
        if (queue[i] == 'B' and queue[i + 1] == 'G'):
            next_queue[i] = 'G'
            next_queue[i + 1] = 'B'
        if (next_queue[i] is None):
            next_queue[i] = queue[i]
    T -= 1
    queue = next_queue
print(''.join(queue))
