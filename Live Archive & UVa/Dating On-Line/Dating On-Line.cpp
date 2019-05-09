/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=5911
Tags: Geometry
Status: Accepted
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

#define debugx(x) cerr << #x << ": " << x << endl
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

ostream &operator<<(ostream &strm, const Vector2D<double> &a)
{
    return strm << '(' << a.x << ", " << a.y << ')';
}

template <typename t>
double triangle_area(Vector2D<t> &a, Vector2D<t> &b, Vector2D<t> &c) // area of triangle between a, b and c
{
    double area = ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y))) / 2;
    if (area < 0)
        return area * -1; // faster than using absolute value
    return area;
}

double polygon_area(deque<int> polygon, int n)
{
    Vector2D<double> C(0.0, 0.0);
    double area = 0.0;
    repx(i, 1, n + 1)
    {
        int s1 = polygon[i - 1];
        int s2 = polygon[i % n];
        Vector2D<double> A(s1, 0);
        Vector2D<double> B(cos((PI / 180.0) * (360.0 / n)) * s2, sin((PI / 180.0) * (360.0 / n)) * s2);
        area += triangle_area<double>(A, B, C);
    }
    return area;
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
        vi scores;

        double min_distance = 1000;
        rep(i, n)
        {
            int s;
            cin >> s;
            scores.eb(s);
        }
        sort(scores.rbegin(), scores.rend());

        deque<int> scores_ordered;

        rep(i, n)
        {
            if (i % 2 == 0)
                scores_ordered.eb(scores[i]);
            else
                scores_ordered.insert(scores_ordered.begin(), scores[i]);
        }

        cout << polygon_area(scores_ordered, n) << "\n";
    }
}