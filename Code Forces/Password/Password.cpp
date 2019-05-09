/*
Problem: https://codeforces.com/problemset/problem/126/B
Tags: Strings, KMP
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
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

vector<int> prefix(string &S)
{
    vector<int> p(S.size());
    p[0] = 0;
    for (int i = 1; i < S.size(); ++i)
    {
        p[i] = p[i - 1];
        while (p[i] > 0 && S[p[i]] != S[i])
            p[i] = p[p[i] - 1];
        if (S[p[i]] == S[i])
            p[i]++;
    }
    return p;
}

int KMP(string &P, string &S, vi &pi)
{
    int n = S.length(), m = P.length();
    int j = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && S[i] != P[j])
            j = pi[j - 1];
        if (S[i] == P[j])
            ++j;

        if (j == P.length())
        {
            ans++;
            j = pi[j - 1];
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    vi p = prefix(input);
    string x = input.substr(0, p[p.size() - 1]);

    while (x.size() > 0)
    {
        if (KMP(x, input, p) >= 3)
        {
            cout << x << "\n";
            return 0;
        }
        else
        {
            p = prefix(x);
            x = input.substr(0, p[p.size() - 1]);
        }
    }
    cout << "Just a legend\n";

    return 0;
}