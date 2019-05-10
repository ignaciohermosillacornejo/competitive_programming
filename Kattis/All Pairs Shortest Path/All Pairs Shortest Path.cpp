/*
Problem: https://open.kattis.com/problems/allpairspath
Tags: Graph, FloyWarshall
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define INF INT_MAX

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
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

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

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



graph floydWarshall (const graph g, int V) 
{ 
    graph dist(V, vi(V, -1));

    rep(i, V)
        rep(j, V)
            dist[i][j] = g[i][j]; 
  
    rep(k, V)
        rep(i, V)
            rep(j, V)
                if (dist[i][k] + dist[k][j] < dist[i][j] &&
                    dist[i][k] != INF                    &&
                    dist[k][j] != INF)
                    dist[i][j] = dist[i][k] + dist[k][j];
        
   return dist;
}

int main()
{
    int n, m, q;
    int test_case = 0;
    while(cin >> n >> m >> q)
    {
        if (n == 0)
            break;

        // we print a new line between each test case
        if (test_case > 0)
            cout << "\n";
        test_case++;

        graph g(n, vi(n, INF));

        // going from i to i is always 0, unless it's part of a negative cycle
        rep(i, n)
            g[i][i] = 0;

        rep(i, m)
        {
            int a, b, w;
            cin >> a >> b >> w;
            g[a][b] = min(g[a][b], w);
        }

        graph res = floydWarshall(g, n);

        // mark all elements that are part of a negative cycle
        rep(i, n)
            rep(j, n)
                rep(k, n)
                {
                    if (res[k][k] < 0 && res[i][k] != INF && res[k][j] != INF)
                        res[i][j] = -INF;
                }




        //debugm(res);

        // answer queries
        rep(i, q)
        {
            int a, b;
            cin >> a >> b;
            if (res[a][b] == INF)
                cout << "Impossible\n";
            else if (res[a][b] == -INF)
                cout << "-Infinity\n";
            else
                cout << res[a][b] << "\n";
        }
    }
}