#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

class Dinic
{
    struct edge
    {
        int to, rev;
        ll f, cap;
    };

    vector<vector<edge>> g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;

    bool bfs(int start, int finish)
    {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail)
        {
            int u = q[head++];
            for (const edge &e : g[u])
            {
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap)
                {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }

    ll dfs(int u, ll f)
    {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i)
        {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if (df > 0)
            {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

  public:
    Dinic(int n)
    {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }

    void add_edge(int u, int v, ll cap)
    {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
        g[u].push_back(a);
        g[v].push_back(b);
    }

    ll max_flow(int source, int dest)
    {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest))
        {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};

int main()
{
    int R;
    int C;
    cin >> R >> C;
    Dinic d(R * C);
    // Mark all the vertices as not visited
    bool *visited = new bool[R * C];
    for (int i = 0; i < R * C; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<tuple<int, int, int>> queue;

    // Mark the current node as visited and enqueue it
    visited[0] = true;
    queue.push_back(make_tuple(0, 0, 0));

    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        tuple<int, int, int> current = queue.front(); queue.pop_front();
        int row = get<0>(current);
        int col = get<1>(current);
        int current_p = (row * R) + col;
        int color = get<2>(current);


        if (color == 0)
            d.add_edge(0, current_p + 1, INT_MAX);
        else 
            d.add_edge(current_p, R * C + 1 , INT_MAX);

        // up
        int up = ((row - 1) * R) + col;
        int down = ((row + 1) * R) + col;
        int left = (row * R) + col - 1;
        int right = (row * R) + col + 1;
        if (row > 0 && !visited[up])
        {
            if (color == 0)
                d.add_edge(current_p + 1, up + 1, 1);
            visited[up] = true;
            queue.emplace_back(make_tuple(row - 1, col, 1 - color));
        }
        // down
        if (row < R - 1 && !visited[down])
        {
            if (color == 0)
                d.add_edge(current_p + 1, down + 1, 1);
            visited[down] = true;
            queue.emplace_back(make_tuple(row + 1, col, 1 - color));
        }
        // left
        if (col > 0 && !visited[left])
        {
            if (color == 0)
                d.add_edge(current_p + 1, left + 1, 1);
            visited[left] = true;
            queue.emplace_back(make_tuple(row, col - 1, 1 - color));
        }
        // right
        if (col < C - 1 && !visited[right])
        {
            if (color == 0)
                d.add_edge(current_p + 1, right + 1, 1);
            visited[right] = true;
        }

    }
}
