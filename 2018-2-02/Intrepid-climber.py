n, f = input().split()
n = int(n)
f = int(f)
graph_up = [[] for _ in range(n)]
graph_down = [[] for _ in range(n)]
costs = [0 for _ in range(n)]
max_cost = 0
total_cost = 0
visited = [False for _ in range(n)]
friends = [False for _ in range(n)]

def dfs_up(start):
    stack = [start]
    while(stack):
        u = stack.pop()
        visited[u] = True
        friends[u] = True
        v = graph_up[u][0]
        if (not visited[v] and v != 0):
            stack.append(v)

def dfs_down(start):
    stack = [start]
    while(stack):
        u = stack.pop()
        for elem in graph_down[u]:
            v = elem[0]
            c = elem[1]
            if (friends[v]):
                costs[v] = costs[u] + c
                stack.append(v)
                global total_cost
                total_cost += c
                global max_cost
                max_cost = max(max_cost, costs[v])
    
for _ in range(n - 1):
    a, b, c = input().split() 
    a = int(a)
    b = int(b)
    c = int(c)
    graph_down[a - 1].append((b - 1, c))
    graph_up[b - 1] = (a - 1, c)
for u in input().split():
    dfs_up(int(u) - 1)

dfs_down(0)
print(total_cost - max_cost)
