/*
Problem: https://codeforces.com/problemset/problem/609/E
Tags: Match, Tree, LCA
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define debugx(x) // cerr<<#x<<": "<<x<<endl

struct edge
{
    int u, v;
    ll w;
    edge(int u, int v, ll w) : u(u), v(v), w(w) {}

    bool operator<(const edge &other) const
    {
        return w > other.w;
    }
};

int inline Log2(unsigned int x)
{
    return 31 - __builtin_clz(x);
}
int inline Log2ll(unsigned long long x)
{
    return 63 - __builtin_clzll(x);
}

class LcaTree
{
    int n;
    vi parent;
    vi level;
    vvi P;
    vvll W;

  public:
    ll sum;
    vi root;

    LcaTree(int n)
    {
        this->n = n;
        parent.assign(n, -1);
        level.assign(n, -1);
        P.assign(n, vi(Log2(n) + 1, -1));
        W.assign(n, vll(Log2(n) + 1, 0));
        sum = 0;
        root.assign(n, -1);
    }
    void addLeaf(int index, int par, ll weight)
    {
        sum += weight;
        parent[index] = par;
        level[index] = level[par] + 1;
        P[index][0] = par;
        W[index][0] = weight;
        root[index] = root[par];
        for (int j = 1; (1 << j) < n; ++j)
        {
            if (P[index][j - 1] != -1)
            {
                P[index][j] = P[P[index][j - 1]][j - 1];
                W[index][j] = max(W[index][j - 1], W[P[index][j - 1]][j - 1]);
            }
        }
    }
    void addRoot(int index)
    {
        parent[index] = index;
        level[index] = 0;
        root[index] = index;
    }
    int lca(int u, int v)
    {
        //if(root[u] != root[v] || root[u] == -1)
        //    return -1;
        if (level[u] < level[v])
            swap(u, v);
        ll answer = W[u][0];
        debugx(answer);
        int dist = level[u] - level[v];
        while (dist != 0)
        {
            int raise = Log2(dist);
            if (true) //(not(dist == (1 << raise) && P[u][raise] == v))
            {
                answer = max(answer, W[u][raise]);
                debugx(answer);
            }
            u = P[u][raise];
            dist -= (1 << raise);
        }
        if (u == v)
        {
            //cout << "\nson iguales!\n";
            return answer;
        }
        answer = max(answer, W[v][0]);
        for (int j = Log2(n); j >= 0; --j)
        {
            //cout << "J: " << j << endl;
            // u: 1
            // v: 5
            if (P[u][j] != -1 && P[u][j] != P[v][j])
            {
                answer = max(answer, max(W[u][j], W[v][j]));
                debugx(answer);
                u = P[u][j];
                v = P[v][j];
            }
        }
        answer = max(answer, max(W[u][0], W[v][0]));
        debugx(answer);
        return answer;
    }
};

int main()
{
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vvi adj(n);
    LcaTree tree(n);
    if (m == 0)
    {
        return 0;
    }

    vector<edge> ordered_input;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        adj[u - 1].emplace_back(i);
        adj[v - 1].emplace_back(i);
        ordered_input.emplace_back(edge(u - 1, v - 1, w));
    }

    tree.addRoot(0);

    priority_queue<edge> q;

    for (auto v : adj[0])
    {
        q.push(ordered_input[v]);
    }

    cout << endl;
    ll total = 0;
    while (!q.empty())
    {
        edge e = q.top();
        //cout << "---------" << endl;
        //cout << e.u << " " << e.v << " " << e.w << endl;
        //cout << "---------" << endl << endl;
        q.pop();
        //if (total > 1000) break;
        if (tree.root[e.u] == -1)
        {
            //cout << e.u << " " << e.v  << " " << e.w << endl;
            tree.addLeaf(e.u, e.v, e.w);
            //cout << tree.root[e.u] << endl;
            for (auto k : adj[e.u])
                q.push(ordered_input[k]);
        }
        else if (tree.root[e.v] == -1)
        {
            //cout << e.v << " " << e.u << " " << e.w << endl;
            tree.addLeaf(e.v, e.u, e.w);
            //cout << tree.root[e.v] << endl;
            for (auto k : adj[e.v])
                q.push(ordered_input[k]);
        }
    }
    //cout << endl;
    //cout << tree.sum << endl;
    //cout << total << endl;
    //cout << endl;
    for (int i = 0; i < m; i++)
    {
        //tree.lca(ordered_input[i].u, ordered_input[i].v);

        cout << tree.sum + ordered_input[i].w - tree.lca(ordered_input[i].u, ordered_input[i].v) << endl;
    }
}