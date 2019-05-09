/*
Problem: https://codeforces.com/problemset/problem/277/A
Tags: Graph, DFS, Flood Fill
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout << endl
#define debugv(v) cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) cerr<<#x<<": "<<x<<endl
#define debugp(p) cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))

vector<bool> visited;
graph g;

void dfs(int start)
{
    visited[start] = true;
    for (auto neighbour : g[start])
    {
        if (!visited[neighbour])
            dfs(neighbour);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    g.assign(n + m, vi());
    visited.assign(n + m, false);

    bool bipartite = false;

    /* 
    bipartite graph, from every person we connect to all the languages
    */
    rep(person, n)
    {
        int k; cin >> k;
        rep(j, k)
        {
            bipartite = true;
            int language; cin >> language;
            int language_index = language + n - 1;
            g[person].push_back(language_index);
            g[language_index].push_back(person);
        } 
    }

    int count = 0;

    // edge case: nobady knows any languages, then output should be n and not n - 1
    rep(i, n)
    {
        if (!visited[i])
        {
            count+=1;
            dfs(i);
        }
    }

    if (bipartite)
        cout << count - 1 << "\n";
    else
        cout << n << "\n";
    
}