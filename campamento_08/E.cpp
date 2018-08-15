#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

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
    int n, sink, supposed_flow;

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

    void reset(int n)
    {
        rep(i, n) // clear all the edges
            for (auto &e : g[i])
            {
                e.cap = 0;
                e.f = 0;
            }
    }

    void add_edge(int u, int v, ll cap)
    {
        for (auto k : g[u]) // we do not add repeated edges
            if (k.to == v)
            {
                k.cap == cap;
                return;
            }
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
    


    // print all paths from source to dest, substracting flow from the path
    void print_paths(int root)
    {
        if (root == 1)
            cout << " 2\n";
        else
        {
            for (auto &e: g[root])
            {
                if (e.f > 0)
                {
                    if (root == 0)
                        cout << "1";
                    else if (root and root % 2 == 0)
                        cout << " " << (root + 2) / 2 + 1;
                    e.f -= 1;
                    print_paths(e.to);
                    return;
                }
            }
        }
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;

    Dinic d(5000 * 2);
    int case_n = 1;

    while (cin >> k >> n)
    {
        if (k == 0 and n == 0)
            break;
        d.reset(n);
        string line;
        getline(cin, line);
        if (case_n > 1)
            cout << "\n";
        cout << "Case " << case_n << ":\n";
        case_n++;
        for (int i = 0; i < n; ++i)
        {
            getline(cin, line);
            stringstream s;
            if (i >= 2)
            {
                s << line;
                int v;
                int l = 2 * (i - 1);
                int r = 2 * (i - 1) + 1;
                d.add_edge(l, r, 1);
                cout << l << " -> " << r << "\n";
                while (s >> v)
                {
                    v--;
                    if (v == 0)
                    {
                        d.add_edge(v, l, 1);
                        cout << v << " -> " << l << "\n";
                    }
                    else if (v == 1)
                    {
                        d.add_edge(r, v, 1);
                        cout << r << " -> " << v << "\n";
                    }
                    else
                    {
                        d.add_edge(r, 2 * (v - 1), 1);
                        d.add_edge(l, 2 * (v - 1) + 1, 1);
                        cout << r << " -> " << 2 * (v - 1) << "\n";
                        cout << l << " -> " << 2 * (v - 1) + 1 << "\n";
                    }
                }
            }
            else
            {
                s << line;
                int v;
                while (s >> v)
                {
                    v--;
                    if (i == 0)
                    {
                        d.add_edge(0, v, 1);
                    }
                    else
                    {
                        d.add_edge(, 1, 1)
                    }
                }
            }
        }

        if (d.max_flow(0, 1) < k)
            cout << "Impossible\n";
        else
        {
            while(k--)
            {
                d.print_paths(0);
            }
        }
    }
}