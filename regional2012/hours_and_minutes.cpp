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

int main(int argc, char const *argv[])
{
    set<int> s;
    int i = 0, j = 0;
    do
    {
        i++;
        i %= 60;
        if (i % 12 == 0)
            j++;
        s.emplace(abs(i - j) * 6);
    } while (j != 12);

    int a;
    while (cin >> a)
    {
        if (s.find(a) != s.end())
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}
