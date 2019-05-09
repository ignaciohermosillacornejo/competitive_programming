/*
Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1312
Tags: DP, Top-Down
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
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

graph balls;
graph dp;
graph accum;
int n;

int max_pyramid(int row, int col)
{
    if (dp[row][col] != -1)
        return dp[row][col];

    dp[row][col] = 0;

    // base case (bottom right of the pyramid)
    if (row == n - 1 and col == n - 1)
    {
        return dp[row][col] = max(accum[row][col], dp[row][col]);
    }

    // we ask the question to the ball above it, when we are not in the diagonal
    if (row > col)
    {
        dp[row][col] = max(dp[row][col], max_pyramid(row - 1, col));
    }

    // we choose to take the ball and ask the new pyramid to the right
    // unless we are at the right-most diagonal
    int score = accum[row][col] + max_pyramid(min(n - 1, row + 1), col + 1);

    return dp[row][col] = max(dp[row][col], score);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        balls.assign(n, vi(n, 0));
        dp.assign(n, vi(n, -1));
        accum.assign(n, vi(n, 0));

        rep(size, n)
        {
            rep(pos, size + 1)
            {
                cin >> balls[size][pos];
                accum[size][pos] = balls[size][pos] + accum[max(0, size - 1)][pos];
            }
        }
        cout << max_pyramid(n - 1, 0) << "\n";
    }
}