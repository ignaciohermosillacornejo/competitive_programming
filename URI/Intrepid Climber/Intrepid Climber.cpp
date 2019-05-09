/*
Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1751
Tags: Graph, Tree, DFS
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

int n, f;
wgraph graph_down;
vi graph_up;
vi costs;
vector<bool> visited, friends;
int total_cost = 0;
int max_cost = 0;

// amortized O(n)
void dfs_up(int start)
{
    visited[start] = true;
    friends[start] = true;
    int father = graph_up[start];
    if (!visited[father] && father != 0)
        dfs_up(father);
}

void dfs_down(int start)
{
    for (auto child: graph_down[start])
    {
        if (friends[child.first])
        {
            costs[child.first] = costs[start] + child.second;
            total_cost += child.second;
            dfs_down(child.first);
            max_cost = max(max_cost, costs[child.first]);
        }
    }
}

int main()
{
    cin >> n >> f;

    graph_up.assign(n, 0);
    graph_down.assign(n, vii());
    visited.assign(n, false);
    friends.assign(n, false);
    costs.assign(n, 0);

    rep(i, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph_down[a].push_back(make_pair(b, c));
        graph_up[b] = a;
    }
    rep(i, f)
    {
        int start;
        cin >> start;
        start--;
        dfs_up(start);
    }

    dfs_down(0);

    cout << total_cost - max_cost << "\n";
}