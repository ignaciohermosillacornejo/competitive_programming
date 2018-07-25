#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> graph;
typedef vector<vector<par>> wgraph;

vll egcd(ll n, ll m)
{
    ll r0 = n, r1 = m;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;

    while (r1 != 0)
    {
        ll q = r0 / r1;
        ll r = r0 - q * r1;
        r0 = r1;
        r1 = r;
        ll s = s0 - q * s1;
        s0 = s1;
        s1 = s;
        ll t = t0 - q * t1;
        t0 = t1;
        t1 = t;
    }
    return {r0, s0, t0};
}

ll fn_to_ternary(ll x, ll y, ll a, ll b, ll n){
    return a + n*y + b - n*x;
}


int main()
{
    ll x, y, z;
    while(cin >> x >> y >> z)
    {
        if (x == y == z == 0) return 0;
        if (__gcd(x, y) % z != 0) cout << "Unquibable!\n";
        else
        {
            vll g = egcd(x, y);
            x/=g[0];
            y/=g[0];
            ll a = (z/g[0])*g[1];
            ll b = (z/g[0])*g[2];

        }
        
    }

}