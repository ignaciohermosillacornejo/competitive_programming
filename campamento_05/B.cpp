#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;
typedef vector<vpar> vvpar;

struct Point
{
    vpar arr;
    
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3); //123.000

    int n;
    while (cin >> n)
    {
        vvpar tiles(n);
        rep(i, n)
        {
            int k; cin >> k;
            rep(j, n)
            {
                int a, b; cin >> a >> b;
                tiles[i].eb(a, b);
            }
        }
    }
}