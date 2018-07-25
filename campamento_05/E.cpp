#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long intt;
typedef vector<intt> vi;
typedef pair<intt, intt> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<intt> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};
double cross(Point &a, Point &b, Point &c)
{
    double dx0 = b.x - a.x, dy0 = b.y - a.y;
    double dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}
int orientation(Point &a, Point &b, Point &c)
{
    double tmp = cross(a, b, c);
    return tmp < 0 ? -1 : (tmp == 0 ? 0 : 1);
}
struct line
{
    Point A, B;
    line(double x1, double y1, double x2, double y2) : A(x1, y1), B(x2, y2) {}
    bool intersect(line &o)
    {
        int o11 = orientation(A, o.A, o.B);
        int o12 = orientation(B, o.A, o.B);
        int o21 = orientation(A, B, o.A);
        int o22 = orientation(A, B, o.B);

        return (o11 != o12) and (o21 != o22);
    }
};

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        vector<line> lines;
        while (n--)
        {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            lines.eb(x1, y1, x2, y2);
        }
        n = lines.size();
        int count = 0;
        rep(i, n) repx(j, i+1, n) repx(k, j+1, n)
        {
            if (lines[i].intersect(lines[j]) and lines[i].intersect(lines[k]) and lines[k].intersect(lines[j]))
                count++;
        }
        cout << count << '\n';
    }

    return 0;
}