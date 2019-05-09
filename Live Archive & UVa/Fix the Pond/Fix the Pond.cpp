/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=572&problem=4147&mosmsg=Submission+received+with+ID+2543606
Tags: Graph, DFS
Status: Runetime Error
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugv(v)                              \
    cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
    cerr << endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl
#endif

void add_all_edges(graph &g, int n)
{
    // add all horizontal edges
    rep(row, 2 * n)
    {
        repx(col, 1, 2 * n + 1)
        {
            int right = col + (2 * n + 1) * row;
            int left = right - 1;
            g[right].eb(left);
            g[left].eb(right);
        }
    }
    // add all vertical edges
    repx(row, 1, 2 * n)
    {
        rep(col, 2 * n + 1)
        {
            int down = col + (2 * n + 1) * row;
            int up = down - (2 * n + 1);
            g[down].eb(up);
            g[up].eb(down);
        }
    }
}

void disconnect_edge(graph &g, int pos1, int pos2)
{
    g[pos1].erase(find(g[pos1].begin(), g[pos1].end(), pos2));
    g[pos2].erase(find(g[pos2].begin(), g[pos2].end(), pos1));
}

void dfs_r(graph &g, vi &visited, int u)
{
    visited[u] = 0;
    for (int v : g[u])
        if (visited[v])
            dfs_r(g, visited, v);
}

int main()
{
    int n;
    while (cin >> n)
    {
        graph g((2 * n) * (2 * n + 1));
        vi visited((2 * n) * (2 * n + 1), 1);
        add_all_edges(g, n);
        repx(line, 1, 2 * n - 1 + 1)
        {
            string s;
            cin >> s;
            repx(c, 1, n + 1)
            {
                char barrier = s[c - 1];
                int i, j;
                if (line % 2 == 1) // if line is odd
                {
                    i = line;
                    j = 2 * c - 1;
                }
                else // line is even
                {
                    i = line;
                    j = 2 * c;
                }
                i--;
                j--;
                int top_left = i * (2 * n + 1) + j;
                int top_right = top_left + 1;
                int botom_left = top_left + (2 * n + 1);
                int botom_right = botom_left + 1;
                if (barrier == 'H') // disconnect vertical edges
                {
                    disconnect_edge(g, top_left, botom_left);
                    disconnect_edge(g, top_right, botom_right);
                }
                else // discconect horizontal edges
                {
                    disconnect_edge(g, top_left, top_right);
                    disconnect_edge(g, botom_left, botom_right);
                }
            }
        }
        int count = 0;
        rep(row, 2 * n)
        {
            rep(col, 2 * n + 1)
            {
                int position = col + (2 * n + 1) * row;
                if (visited[position] == 1)
                {
                    count += 1;
                    dfs_r(g, visited, position);
                }
            }
        }
        cout << count - 1 << "\n";
    }
}