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

    void reset()
    {
        supposed_flow = 0;
        rep(i, 37) // clear all the edges
            for (auto &e : g[i])
                {
                    if (i < 27)
                        e.cap = 0;
                    e.f = 0;
                }
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
    string flow(){
        string s = "__________";
        ll fl = max_flow(0, 37);
        if(fl < supposed_flow){
            return "!\n";
        }
        for (int i = 1; i <= 27; ++i){
            for(auto e : g[i]){
                if(e.f == 1)
                {
                    for (auto k : g[e.to])
                    {
                        if (k.to == i and k.f == -1)
                            s[e.to - 27] = i - 1 + 'A';
                    }
                }
            }
        }
        return s + '\n';
    }

    void add_supposed_flow(int f)
    {
        supposed_flow += f;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    Dinic d(1 + 1 + 26 + 10);

    for (int j = 27; j <= 36; ++j) // add the new conections
    {
        d.add_edge(j, 37, 1);
    }

    while (getline(cin, line))
    {
        if (line == "") // we process the old test case and clear our struct
        {
            cout<<d.flow();
            d.reset();
            continue;
        }

        char appl;
        int n_users;

        appl = line[0];
        n_users = line[1] - '0';

        d.add_supposed_flow(n_users);

        d.add_edge(0, appl - 'A' + 1, n_users);

        for (int i = 3; i < line.size() - 1; ++i)
        {
            d.add_edge(appl - 'A' + 1, (line[i] - '0') + 27, 1);
        }
    }
    cout << d.flow();
}