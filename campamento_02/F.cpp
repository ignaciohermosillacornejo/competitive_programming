#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> graph;
typedef vector<vector<par>> wgraph;

//vector<int> dist(n,1e9);
void dijkstra(wgraph &g, int start, vi &dist, vi &parent)
{
    priority_queue<par, vector<par>, greater<par>> q;
    q.push({0, start});
    dist[start] = 0;
    while (not q.empty())
    {
        int priority = q.top().first, u = q.top().second;
        q.pop();
        if (priority != dist[u])
            continue;
        for (par p : g[u])
        {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}

void print_parents(vi & parent, int current)
{
    if (parent[current] != -1)
    {
        print_parents(parent, parent[current]);
        cout << current + 1 << " ";
    }
    else
    {
        cout << current + 1 << " ";
    }
}



int main()
{
    int n; int m;
    cin >> n >> m;
    wgraph g(n);
    vi parent(n, -1);
    vi dist(n, 1e9);
    for(int k = 0; k < m; ++k)
    {
        int i; int j; int w;
        cin >> i >> j >> w;
        i--; j--;
        g[i].emplace_back(make_pair(j, w));
        g[j].emplace_back(make_pair(i, w));
    }
    dijkstra(g, 0, dist, parent);
    if (dist[n - 1] < 1e9)
    {
        int current = n - 1;
        print_parents(parent, n - 1);
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}
