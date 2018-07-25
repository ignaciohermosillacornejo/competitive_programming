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

#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(vi &S)
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

int KMP(vi &P, vi &S)
{
    vi pi = prefix(S);
    int n = S.size(), m = P.size();
    int j = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && S[i] != P[j])
            j = pi[j - 1];
        if (S[i] == P[j])
            ++j;

        if (j == P.size())
        {
            ++ans;
            j = pi[j - 1];
        }
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vi S_in(n);
    vi P_in(w);
    vi S(n - 1);
    vi P(w - 1);

    rep(i, n)
    {
        int x;
        cin >> x;
        S_in[i] = x;
    }
    rep(i, w)
    {
        int x;
        cin >> x;
        P_in[i] = x;
    }
    for (int i = 1; i < n; i++)
    {
        S[i - 1] = S_in[i] - S_in[i - 1];
    }
    for (int i = 1; i < w; i++)
    {
        P[i - 1] = P_in[i] - P_in[i - 1];
    }

    if (w == 1 and n == 1)
    {
        cout << "1\n";
    }
    else if (w == 1)
    {
        cout << n << "\n";
    }
    else if (n == 1)
    {
        cout << "0\n";
    }
    else
    {
        cout << KMP(P, S) << "\n";
    }

    return 0;
}