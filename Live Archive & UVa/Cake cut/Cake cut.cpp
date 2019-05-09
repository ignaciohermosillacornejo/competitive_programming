/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=5217
Tags: Geometry
Status: TLE
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd
#define PI 3.14159265

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v)                              \
    cerr << #v << ":";                         \
    rep(i, (int)v.size()) cerr << " " << v[i]; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl
#endif

template <class t>
class Vector2D
{
  public:
    t x, y;

    friend ostream &operator<<(ostream &strm, const Vector2D &a);

    Vector2D(t x, t y) : x(x), y(y) {}
    Vector2D() {}

    Vector2D operator+(const Vector2D &o)
    {
        return Vector2D(x + o.x, y + o.y);
    }

    Vector2D operator-(const Vector2D &o)
    {
        return Vector2D(x - o.x, y - o.y);
    }

    Vector2D operator*(t c) const // scalar product
    {
        return Vector2D(c * x, c * y);
    }

    t dot(const Vector2D &o)
    {
        return x * o.x + y * o.y;
    }

    t dist_sqr(const Vector2D &o)
    {
        return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
    }
};

ostream &operator<<(ostream &strm, const Vector2D<int> &a)
{
    return strm << '(' << a.x << ", " << a.y << ')';
}

template <typename t>
ll triangle_volume(Vector2D<t> &a, Vector2D<t> &b, Vector2D<t> &c) // area of triangle between a, b and c
{
    ll area = ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y)));
    return fabs(area);
}

ll polygon_volume(vector<Vector2D<ll>> polygon, int n)
{
    ll area = 0.0;
    repx(i, 2, n)
    {
        area += triangle_volume<ll>(polygon[0], polygon[i - 1], polygon[i]);
    }
    return area;
}

// function to check if we must increase w or stay
bool check_step(vector<Vector2D<ll>> polygon, int n, int v, int w, ll l_volume, ll total_volume, ll diff)
{
    ll step_size = triangle_volume<ll>(polygon[v % n], polygon[w % n], polygon[(w + 1) % n]);
    ll n_l_area = l_volume + step_size;
    ll n_r_area = total_volume - n_l_area;
    ll n_diff = fabs(n_l_area - n_r_area);
    return n_diff < diff;
}

// function to perfom a step foward and advance w
void step_w(vector<Vector2D<ll>> polygon, int n, int v, int &w, ll &l_volume, ll total_volume, ll &diff)
{
    ll step_size = triangle_volume<ll>(polygon[v % n], polygon[w % n], polygon[(w + 1) % n]);
    l_volume = l_volume + step_size; //triangle_area<double>(polygon[v%n], polygon[w % n], polygon[(w + 1) % n]);
    ll r_volume = total_volume - l_volume;
    diff = fabs(l_volume - r_volume);
    debugx(l_volume);
    //cout << "step w: " << w << "(v, w %n , (w+1)%n) " << v << " " << w << " " << (w + 1) % n << " " << step_size << " " << diff << "\n";
    w++;
}

// function to perfom a step foward of v after a step in w
void step_v(vector<Vector2D<ll>> polygon, int n, int v, int &w, ll &l_volume, ll total_volume, ll &diff)
{
    ll step_size = triangle_volume<ll>(polygon[v % n], polygon[(v + 1) % n], polygon[(w) % n]);
    l_volume -= step_size;
    ll r_area = total_volume - l_volume;
    diff = fabs(l_volume - r_area);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(1);
    int n;
    while (cin >> n)
    {
        vector<Vector2D<ll>> polygon(n);
        rep(i, n) // read the input
        {
            Vector2D<ll> p;
            cin >> p.x >> p.y;
            polygon[i] = p;
        }

        ll total_volume = polygon_volume(polygon, n);
        ll l_volume = 0;
        ll diff = total_volume - l_volume;
        ll max_diff = -1;
        ll max_l_volume = 0;
        int w = 1;

        rep(v, n)
        {
            //cout << "\n\n";
            debugx(v);
            while (check_step(polygon, n, v, w, l_volume, total_volume, diff))
            {
                step_w(polygon, n, v, w, l_volume, total_volume, diff);
            }
            debugx(l_volume);
            debugx(diff);
            if (diff > max_diff)
            {
                max_diff = diff;
                max_l_volume = l_volume;
            }
            step_v(polygon, n, v, w, l_volume, total_volume, diff);
            debugx(l_volume);
        }
        cout << max(max_l_volume, total_volume - max_l_volume) << " " << min(max_l_volume, total_volume - max_l_volume) << "\n";
        //cout << triangle_volume(polygon[0], polygon[2], polygon[3]) << "\n";
    }
}