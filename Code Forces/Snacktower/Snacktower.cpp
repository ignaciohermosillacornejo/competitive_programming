/*
Problem: https://codeforces.com/problemset/problem/767/A
Tags: Implementation
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long intt;
typedef vector<intt> vi;
typedef pair<intt, intt> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<intt> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    rep(i, n)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    set<int, greater<int>> s;
    int current = n;
    rep(i, n)
    {
        s.insert(arr[i]);
        bool not_first = false;
        while (s.find(current) != s.end())
        {
            if (not_first)
            {
                cout << " ";
            }
            cout << *s.begin();
            s.erase(current);
            current--;
            not_first = true;
        }
        cout << "\n";
    }
}


