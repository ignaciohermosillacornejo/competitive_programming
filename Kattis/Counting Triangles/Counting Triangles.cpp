/*
Problem: https://open.kattis.com/problems/countingtriangles
Tags: Geometry, Brute Force
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

#define debugx(x)  cerr<<#x<<": "<<x<<endl
#define debugv(v)  cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl
#endif

struct Point
{
    double x;
    double y;
};

struct Line
{
    Point a;
    Point b;
};

Point substract(Point &A, Point &B)
{
    Point C;
    C.x = A.x - B.x;
    C.y = A.y - B.y;
    return C;
}

int orientation(Point &a, Point &b, Point &c)
{
    Point d0 = substract(b, a);
    Point d1 = substract(c, a);
    double cross = d0.x * d1.y - d1.x * d0.y;
    if (cross == 0)
        return 0;

    return (cross > 0) ? 1 : 2;
}

/* https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/ */
bool doIntersect(Line l1, Line l2)
{
    Point p1, q1, p2, q2;
    p1 = l1.a;
    q1 = l1.b;
    p2 = l2.a;
    q2 = l2.b;
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    return false; // Doesn't fall in any of the above cases
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(4);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;

        vector<Line> lines;
        rep(i, n)
        {
            Line line;
            cin >> line.a.x >> line.a.y >> line.b.x >> line.b.y;
            lines.eb(line);
        }
        int count = 0;
        rep(i, n - 2)
        {
            Line l1 = lines[i];
            repx(j, i + 1, n - 1)
            {
                Line l2 = lines[j];
                if (doIntersect(l1, l2))
                {
                    repx(k, j + 1, n)
                    {
                        Line l3 = lines[k];
                        if (doIntersect(l1, l3) and doIntersect(l2, l3))
                            count++;
                    }
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}