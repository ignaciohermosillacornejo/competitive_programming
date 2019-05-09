/*
Problem: https://codeforces.com/problemset/problem/1059/D?locale=en
Tags: Geometry, BinarySearch
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

vii coords;
int n;

bool solution_posible(double radius)
{
    double l = -1e10;
    double r = 1e10;

    rep(i, n)
    {
        if (coords[i].second - (2 * radius) > 0)
            return 0;
        double range = sqrt(coords[i].second * (2 * radius - coords[i].second));
        l = max(l, coords[i].first - range);
        r = min(r, coords[i].first + range);
    }
    return l <= r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // flags para ver si hay un numero positivo y negativo
    bool negative = false;
    bool positive = false;

    // Lectura de input
    cin >> n;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        coords.emplace_back(x, y);
        if (y >= 0)
            positive = true;
        else
            negative = true;
    }

    if (positive && negative)
    {
        cout << -1 << "\n";
        return 0;
    }

    if (negative)
    {
        rep(i, n)
        {
            coords[i].second = coords[i].second * -1;
        }
    }

    double r_min = 0;
    double r_max = 1e17;

    rep(i, 70)
    {
        double mid = (r_min + r_max) / 2;
        if (solution_posible(mid))
        {
            r_max = mid;
        }
        else
        {
            r_min = mid;
        }
    }

    cout.precision(16);
    cout << fixed << (r_max + r_min) / 2 << "\n";

    return 0;
}