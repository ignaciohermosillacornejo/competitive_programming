/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=788&page=show_problem&problem=6210
Tags: Geometry, DP
Status: WA
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

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  //cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

#endif

struct Point
{
    double x, y;
};

struct Tile
{
    int height;
    vector<Point> left_array, right_array;
    double width, min_x, max_x;
};

vector<Tile> tiles;

void print_point(Point p)
{
    cout << "[" << p.x << "," << p.y << "]";
}

void print_tile(Tile &tile)
{
    cout << "TILE\n";
    cout << "min_x: " << tile.min_x << "\n";
    cout << "max_x: " << tile.max_x << "\n";
    cout << "Left Array: ";
    rep(i, tile.left_array.size())
    {
        print_point(tile.left_array[i]);
        cout << " ";
    }
    cout << "\n";

    cout << "Right Array: ";
    rep(i, tile.right_array.size())
    {
        print_point(tile.right_array[i]);
        cout << " ";
    }
    cout << "\n";
}

double min_distance(Point &a, Point &b, Point &c)
{
    double m = (b.y - a.y) / (b.x - a.x);
    double n = a.x - m * a.y;
    double x = (m * c.y) + n;
    return fabs(x - c.x);
}

void calculate_overlap(Tile &left_tile, Tile &right_tile)
{
    vector<Point> left_points = left_tile.right_array;
    vector<Point> right_points = right_tile.left_array;

    int l = left_points.size() - 1;
    int r = right_points.size() - 1;

    double overlap = 1e9;

    while (l > 0)
    {
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        tiles.clear();
        rep(i, n)
        {
            Tile tile;
            tiles.eb(tile);
            int k;
            cin >> k;
            rep(j, k)
            {
                Point p;
                cin >> p.x >> p.y;
                if (j == 0 or tile.left_array.size() > 2 or (p.y != 0 and p.y == tile.right_array.back().y))
                {
                    tile.left_array.eb(p);
                    tile.min_x = min(tile.min_x, p.x);
                }
                else
                {
                    tile.right_array.eb(p);
                    tile.max_x = max(tile.max_x, p.x);
                }
            }
            reverse(tile.left_array.begin() + 1, tile.left_array.end()); // we reverse left array expect elem 0 because its in place
            tile.width = tile.max_x - tile.min_x;
            tile.height = tile.left_array.back().y;
        }
    }
}