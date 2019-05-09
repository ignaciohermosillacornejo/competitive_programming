/*
Problem: https://open.kattis.com/submissions/4161247
Tags: Implementation
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef vector<ii> vii;
typedef vector<vii> wgraph;

#define rep(i, n) for (size_t i = 0; i < (size_t)n; ++i)
#define repx(i, a, b) for (size_t i = a; i < (size_t)b; ++i)
#define invrep(i, a, b) for (size_t i = b; i >= (size_t)a; --i)

#define pb push_back
#define eb emplace_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gdc __gcd

int main()
{
    int n;
    cin >> n;
    ll a[3] = {0, 0, 0};
    ll b[3] = {0, 0, 0};
    repx(i, 1, n + 1)
    {
        ll x;
        cin >> x;
        a[i % 3] += x;
    }
    repx(i, 1, n + 1)
    {
        ll x;
        cin >> x;
        b[i % 3] += x;
    }
    ll c[3] = {0, 0, 0};
    repx(i, 1, 4) repx(j, 1, 4)
    {
        c[(i + j) % 3] += a[i % 3] * b[j % 3];
    }
    cout << c[0] << " " << c[1] << " " << c[2] << endl;
}