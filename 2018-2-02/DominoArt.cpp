#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                         \
    cerr << #m << endl;                                                    \
    rep(i, (int)m.size())                                                  \
    {                                                                      \
        cerr << i << ":";                                                  \
        rep(j, (int)m[i].size())                                           \
        {                                                                  \
            cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        }                                                                  \
        cerr << endl;                                                      \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

#endif

bool bfs(wgraph &g, vi &parent, int s, int t)
{
    // Create a visited array and mark all vertices as not visited
    vector<bool> visited(g.size(), false);

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : g[u])
        {
            //cout << "u: " << u << " -> " << v.first << " (" << v.second << ")\n";
            //debugv(visited);
            if (visited[v.first] == false && v.second > 0)
            {
                q.push(v.first);
                parent[v.first] = u;
                visited[v.first] = true;
            }
        }
    }

    // return if we've reached sink in BFS starting from source
    return visited[t];
}

int fordFulkenson(wgraph &g, int s, int t)
{
    vi parent(g.size(), -1);
    int max_flow = 0;
    
    while (bfs(g, parent, 0, 1))
    {
        int path_flow = INT_MAX;
        int v = t;
        while (parent[v] != -1)
        {
            int u = parent[v];
            for (auto &i: g[u])
                if (i.first == v)
                    path_flow = min(path_flow, i.second);
            v = u;
        }
        v = t;
        while (parent[v] != -1)
        {
            int u = parent[v];
            for (auto &i : g[u])
                if (i.first == v)
                    i.second -= path_flow;
            for (auto &i : g[v])
                if (i.first == u)
                    i.second += path_flow;
            v = u;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(4);

    int R, C;
    int case_number = 1;
    while (cin >> R >> C)
    {
        if (R == 0 and C == 0)
            break;

        graph board(R, vi(C, 0));
        int domino_spaces = 0;

        rep(row, R)
        {
            rep(col, C)
            {
                char x;
                cin >> x;
                if (x == '#')
                {
                    board[row][col] = 1;
                    domino_spaces++;
                }
            }
            if (C % 2 == 0) // we make sure to have an odd ammount of colmns so that the value of the cell beneath another is always alternating between odd and even
                board[row].eb(0);
        }

        if (C % 2 == 0)
            C++;

        // construct graph
        // graph has R * C + 2 nodes

        wgraph flow_graph(R * C + 2);

        // node 0 is the start node
        // node 1 is the end node
        rep(row, R)
        {
            rep(col, C)
            {
                if (!board[row][col])
                    continue;

                int cnode = row * C + col + 2;

                if (cnode % 2 == 0)
                {
                    flow_graph[0].eb(cnode, 1);
                }
                else
                {
                    flow_graph[cnode].eb(1, 1);
                }

                // conexion arriba
                if (row > 0 and board[row - 1][col])
                {
                    int up_node = (row - 1) * C + col + 2;
                    flow_graph[cnode].eb(up_node, 1);
                }
                // conexion derecha
                if (col < C - 1 and board[row][col + 1])
                {
                    int right_node = row * C + col + 1 + 2;
                    flow_graph[cnode].eb(right_node, 1);
                }
                // conexion abajo
                if (row < R - 1 and board[row + 1][col])
                {
                    int down_node = (row + 1) * C + col + 2;
                    flow_graph[cnode].eb(down_node, 1);
                }
                // conexion izquierda
                if (col > 0 and board[row][col - 1])
                {
                    int left_node = row * C + col - 1 + 2;
                    flow_graph[cnode].eb(left_node, 1);
                }
            }
        }
        if (fordFulkenson(flow_graph, 0, 1) * 2 == domino_spaces)
        {
            cout << "Case " << case_number << ": Possible\n";
        }
        else
        {
            cout << "Case " << case_number << ": Impossible\n";
        }
        case_number++;
    }
}