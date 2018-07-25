#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<char> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<char>> graph;
typedef vector<vector<par>> wgraph;

int dfs(graph &g, int row, int col, int M, int N, int count, char land)
{
    g[row][col] = land;
    int ans = count;
    if (row > 0 and g[row - 1][col] == land) // up
        ans += dfs(g, row - 1, col, M, N, 1, land);
    if (row + 1 < M and g[row + 1][col] == land) // down
        ans += dfs(g, row + 1, col, M, N, 1, land);
    if (g[row][(col + 1) % N] == land) // right
        ans += dfs(g, row, (col + 1) % N, M, N, 1, land);
    if (g[row][(col + N - 1) % N] == land) // left
        ans += dfs(g, row, (col + N - 1) % N, M, N, 1, land);
    return ans;
}

int main()
{
    int N;
    int M;
    while(cin >> M >> N)
    {
        graph g(M, vi(N, 'l'));
        rep(row, M)
        {
            rep(col, N)
            {
                cin >> g[row][col];
            }
        }
        int X;
        int Y;
        cin >> X >> Y;
        char land = g[X][Y];
        dfs(g, X, Y, M, N, 1, land);
        int max_count = 0;
        
        rep(row, M)
        {
            rep(col, N)
            {
                if (g[row][col] == land)
                    max_count = max(max_count, dfs(g, row, col, M, N, 1, land));
            }
        }
        cout << max_count << "\n";
    }
}