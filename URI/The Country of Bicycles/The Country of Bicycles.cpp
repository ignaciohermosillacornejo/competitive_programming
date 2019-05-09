/*
Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1454
Tags: Graph, Dijkstra
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> graph;
typedef vector<vector<par>> wgraph;

//vector<int> dist(n,1e9);
void dijkstra(wgraph &g, int start, vi &dist)
{
    priority_queue<par, vector<par>, greater<par>> q;
    q.push({LLONG_MIN, start});
    dist[start] = LLONG_MIN;
    while (not q.empty())
    {
        int priority = q.top().first, u = q.top().second;
        q.pop();
        if (priority != dist[u])
            continue;
        for (par p : g[u])
        {
            int v = p.first, w = p.second;
            if (max(dist[u], w) < dist[v])
            {
                dist[v] = max(dist[u], w);
                q.push({dist[v], v});
            }
        }
    }
}
#undef int

int main()
#define int long long
{
    int n, m;
    int contador = 1;
    while (cin >> n >> m)
    {
        if (n == 0)
            return 0;
        cout << "Instancia " << contador << "\n";
        contador++;
        wgraph g(n);
        for (int k = 0; k < m; ++k)
        {
            int i;
            int j;
            int w;
            cin >> i >> j >> w;
            i--;
            j--;
            g[i].emplace_back(j, w);
            g[j].emplace_back(i, w);
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            int a;
            int b;
            vi dist(n, LLONG_MAX);
            cin >> a >> b;
            a--;
            b--;
            dijkstra(g, a, dist);
            if (a == b)
                cout << "0\n";
            else
                cout << dist[b] << "\n";
        }
        cout << endl;
    }
}
