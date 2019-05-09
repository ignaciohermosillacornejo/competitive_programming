/*
Problem: https://www.codepit.io/#/submission/5b7c28c06ea097002368b8e0
Tags: Geometry, Polygon
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

#define debugx(x)  //cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl
#endif

struct Point
{
    ll x;
    ll y;
};

// return A - B
Point substract(Point &A, Point &B)
{
    Point C;
    C.x = A.x - B.x;
    C.y = A.y - B.y;
    return C;
}

ll multiply(Point &a, Point &b, Point &c)
{
    Point d0 = substract(b, a);
    Point d1 = substract(c, a);
    ll cross = d0.x * d1.y - d1.x * d0.y;
    return cross;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(4);
    vector<Point> polygon;
    int N, Q;
    cin >> N >> Q;
    rep(i, N)
    {
        Point p;
        cin >> p.x >> p.y;
        polygon.eb(p);
    }
    rep(i, Q)
    {
        Point point;
        bool flag = true;
        cin >> point.x >> point.y;
        //cout << point.x << " " << point.y << "\n";
        for (int k = 1; k < N + 1; k++)
        {
            //cout << "(" << polygon[k -1].x << ", " << polygon[k - 1].y << ") -> (" << polygon[k%N].x << ", " << polygon[k%N].y << ")\n";
            ll cross = multiply(polygon[k - 1], polygon[k % N], point);
            //cout << cross << "\n";
            if (cross < 0)
            {
                cout << "F\n";
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "D\n";
    }
}
