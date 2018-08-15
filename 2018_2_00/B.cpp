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

ii subtract_par(ii A, ii B)
{
    return make_pair(A.first - B.first, A.second - B.second);
}

int cross_product_2d(ii A, ii B)
{
    return A.first * B.second - B.first * A.second;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(4);
    vii polygon;
    int N, Q;
    cin >> N >> Q;
    rep(i, N)
    {
        int X, Y;
        cin >> X >> Y;
        polygon.eb(X, Y);
    }
    rep(i, Q)
    {
        bool flag = true;
        int px, py;
        cin >> px >> py;
        //cout << px << " " << py << "\n";
        int o_max = 0; int o_min = 0;
        ii point = make_pair(px, py);
        repx(i, 1, N + 1)
        {
            int cross = cross_product_2d(subtract_par(polygon[i - 1], point), subtract_par(polygon[i%N], point));
            if (cross > 0)
                o_max = 1;
            if (cross < 0)
                o_min = -1;
            if (o_max - o_min == 2)
                flag = false;
        }
        if (flag)
        {
            cout << "D\n";
        }
        else
        {
            cout << "F\n";
        }
    }
}
