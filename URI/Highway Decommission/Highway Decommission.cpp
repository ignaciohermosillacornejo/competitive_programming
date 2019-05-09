/*
Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2910
Tags: Graph, Dijkstra
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

//typedef long long ll;
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
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

struct Edge
{
    ll v;
    ll l;
    ll c;

    bool operator<(const Edge &o) const
    {
        return l > o.l || (l == o.l && c > o.c) || (l == o.l && c == o.c && v > o.v);
    }

    Edge(ll v, ll l, ll c) : v(v), l(l), c(c) {}
};

ll dijsktra(vector<vector<Edge>> g, ll start)
{
    ll n = g.size();
    vi length(n, 1e11);
    vi cost(n, 1e11);

    priority_queue<Edge> q;
    q.emplace(start, 0, 0);
    length[start] = 0;
    cost[start] = 0;

    while (!q.empty())
    {
        ll u = q.top().v;
        ll l = q.top().l;
        ll c = q.top().c;
        q.pop();

        if (length[u] < l || length[u] == l && cost[u] < c)
            continue;

        for (auto &v : g[u])
        {
            if (length[v.v] > l + v.l)
            {
                length[v.v] = l + v.l;
                cost[v.v] = v.c;
                q.emplace(v.v, length[v.v], cost[v.v]);
            }
            else if (length[v.v] == l + v.l && cost[v.v] > v.c)
            {
                cost[v.v] = v.c;
                q.emplace(v.v, length[v.v], cost[v.v]);
            }
        }
    }
    ll total_cost = 0;

    rep(i, n)
        total_cost += cost[i];

    return total_cost;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(4);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> routes(n);

    rep(i, m)
    {
        ll a, b, l, c;
        cin >> a >> b >> l >> c;
        a--;
        b--;
        routes[a].eb(b, l, c);
        routes[b].eb(a, l, c);
    }

    cout << dijsktra(routes, 0) << "\n";
}