#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> graph;
typedef vector<vector<par>> wgraph;


void bfs(int start, graph & g, vi & dist)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(not q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist[v] == INT_MAX) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

class LCA
{
    vector<vector<int>> P;
    graph g;
    int n, m;

    void build(int u, int p = -1, int lv = 0)
    {
        parent[u] = p;
        level[u] = lv;
        for (int v : g[u])
            if (v != p)
                build(v, u, lv + 1);
    }

  public:
    vector<int> parent, level;

    LCA(graph & gg, int root)
    {
        g = gg;
        n = g.size();
        parent.resize(n);
        level.resize(n);
        build(root);

        P.assign(n, vector<int>(m = log2(n * 2), -1));
        rep(i, n) P[i][0] = parent[i];
        rep(j, m - 1) rep(i, n) if (P[i][j] != -1)
            P[i][j + 1] = P[P[i][j]][j];
    }

    int operator()(int u, int v)
    {
        if (level[u] < level[v])
            swap(u, v);
        int i = 0, x;
        for (; x = level[u] - level[v]; ++i)
            if (x & 1 << i)
                u = P[u][i];
        if (u == v)
            return u;
        for (++i; i >= 0; --i)
            if (P[u][i] != -1 and P[u][i] != P[v][i])
                u = P[u][i], v = P[v][i];
        return parent[u];
    }
};

int main()
{
    int n;
    while(cin >> n)
    {
        graph g(n);
        rep(i,n-1){
            int a,b;
            cin>>a>>b;
            a--;b--;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        LCA lca(g, 0);



        vi dist_1(n, INT_MAX);
        bfs(0, g, dist_1);
        int index_1 = 0;
        rep(i, n)
            if (dist_1[index_1] < dist_1[i]) index_1 = i;

        vi dist_2(n, INT_MAX);
        bfs(index_1, g, dist_2);
        int index_2 = index_1;
        rep(i, n) if (dist_2[index_2] < dist_2[i]) index_2 = i;
        vi dist_3(n, INT_MAX);
        bfs(index_2, g, dist_3);
        int m; cin >> m;
        rep(i, m)
        {
            int a; int b;
            cin >> a >> b;
            a--; b--;
            cout << max(min(dist_2[a], dist_3[a]), min(dist_2[b], dist_3[b])) << "\n";
        }
    }
}