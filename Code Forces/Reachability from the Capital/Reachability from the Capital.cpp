/*
Problem: https://codeforces.com/problemset/problem/999/E
Tags: Graphs, DFS
Status: WA
Author: Arios
*/

#include <bits/stdc++.h>

using namespace std;

vector< vector<int>> g;
vector<bool> reachableFromS;
vector<bool> visited;
int cnt = 0;

void dfs(int start)
{
    cnt++;
    visited[start] = true;
    for (auto neighbour : g[start])
        if (!reachableFromS[neighbour] && !visited[neighbour])
            dfs(neighbour);
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    g.assign(n, vector<int>());
    reachableFromS.assign(n, false);
    visited.assign(n, false);

    --s;

    // construct the graph
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }

    // we mark all the nodes that we can visit from s
    dfs(s);
    reachableFromS = visited;


    vector<pair<int, int>> amount_reached;
    // for each node that is not reachable from s, we see how many we can visit from there
    // and add them to a list
    for (int i = 0; i < n; ++i)
    {
        if (!reachableFromS[i])
        {
            cnt = 0;
            visited.assign(false, n);
            dfs(i);
            amount_reached.push_back(make_pair(cnt, i));
        }
    }

    // we sort the pairs from the most to the least
    sort(amount_reached.end(), amount_reached.begin());

    visited = reachableFromS;

    int ans = 0;

    for (auto it : amount_reached)
    {
        if (!visited[it.second])
        {
            ++ans;
            dfs(it.second);
        }
    }

    cout << ans << endl;

    return 0;
}