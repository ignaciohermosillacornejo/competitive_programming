/*
Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5028
Tags: Geometry, Vectors
Status:
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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
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

double calculate_distance(Vector2D<int> &a, Vector2D<int> &b, Vector2D<int> &c) // distance between segmente ab and Vector2D<int> c
{
    Vector2D<double> v(a.x, a.y), w(b.x, b.y), p(c.x, c.y);
    const double l2 = v.dist_sqr(w);

    double t = max(0.0, min(1.0, (p - v).dot(w - v) / l2));
    const Vector2D<double> projection = v + (w - v) * t;
    return sqrt(p.dist_sqr(projection));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(3);
    int n;

    while (cin >> n)
    {
        vector<Vector2D<int>> boundaries;
        Vector2D<int> redis;
        cin >> redis.x >> redis.y;
        double min_distance = 1000;
        rep(i, n)
        {
            Vector2D<int> p;
            cin >> p.x >> p.y;
            boundaries.eb(p);
        }
        repx(i, 1, n + 1)
        {
            double distance = calculate_distance(boundaries[i - 1], boundaries[i % n], redis);
            if (distance < min_distance)
                min_distance = distance;
        }
        cout << min_distance << "\n";
    }
}