#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define eb emplace_back

void dfs(vvi &g, int u, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : g[u])
    {
        if (not vis[v])
        {
            dfs(g, v, vis);
        }
    }
}

int main()
{
    int n;
    int m;
    int case_number = 1;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            return 0;
        }
        vvi G(n);
        int answer = 0;

        while (m--)
        {
            int i;
            int j;
            cin >> i >> j;
            i--;
            j--;
            G[i].eb(j);
            G[j].eb(i);
        }
        vector<bool> vis(n, false);

        rep(u, n) if (not vis[u])
        {
            answer++;
            dfs(G, u, vis);
        }
        cout << "Case " << case_number << ": " << answer << "\n";
        case_number++;
    }
}