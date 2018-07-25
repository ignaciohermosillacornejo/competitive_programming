#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, x, n) for (int i = x; i < (int)n; ++i)
#define invrep(i, n) for (int i = n; i--;)
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gcd __gcd

typedef pair<int, int> par;
typedef vector<vector<par>> wgraph;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main(){
    int n_casos;
    cin >> n_casos;

    while(n_casos--)
    {
        int nGrafo, eGrafo;
        cin >> nGrafo >> eGrafo; 
        vi dist(nGrafo, 1e9);
        int start = 0;
        dist[start] = 0;
        wgraph g(nGrafo);
        rep(i, eGrafo)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].eb(v,w);
        }

        rep(i, nGrafo - 1) rep(u, nGrafo) for (par p : g[u])
        {
            int v = p.first, w = p.second;
            dist[v] = min(dist[v], dist[u] + w);
        }
        //después de ejecutar lo anterior
        bool hayCicloNegativo = false;
        rep(u, nGrafo) for (par p : g[u])
        {
            int v = p.first, w = p.second;
            if (dist[v] > dist[u] + w)
                hayCicloNegativo = true;
        }
        if (hayCicloNegativo)
        {
            cout << "possible\n";
        }
        else
        {
            cout << "not possible\n";
        }
    }

}
