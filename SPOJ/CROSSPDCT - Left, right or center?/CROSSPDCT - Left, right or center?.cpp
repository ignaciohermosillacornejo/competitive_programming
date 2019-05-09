/*
Problem: https://www.spoj.com/problems/CROSSPDCT/
Tags: Geometry, Crossproduct
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
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

Point substract(Point &A, Point &B)
{
    Point C;
    C.x = A.x - B.x;
    C.y = A.y - B.y;
    return C;
}

ll multiply(Point &A, Point &B, Point &C)
{
    Point B2 = substract(B, A);
    Point C2 = substract(C, A);
    return B2.x * C2.y - B.y * C.x;
}

int main()
{
    Point A, B;
    int q;
    cin >> A.x >> A.y >> B.x >> B.y >> q;
    while (q--)
    {
        Point C;
        cin >> C.x >> C.y;
        ll answer = multiply(A, B, C);
        if (answer == 0)
            cout << "C\n";
        else if (answer < 0)
            cout << "D\n";
        else
            cout << "I\n";
    }
    return 0;
}