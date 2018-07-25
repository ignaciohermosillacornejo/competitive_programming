/* https://www.urionlinejudge.com.br/judge/en/runs */
#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int max_value = 501;
int r, c, n;
int current_cost = 0;
ll tree[max_value][max_value];
int costs[max_value][max_value];
int distance_x[max_value][max_value];
int distance_y[max_value][max_value];
priority_queue<point> q;

/* Custom struct for our priority q */
struct point
{
    int x;
    int y;
    ll c;

    point(int x, int y, ll c) : x(x), y(y), c(c) {}

    bool operator<(const point &other) const
    {
        return c > other.c;
    }
};

/* 2D Fenwick tree sum operation */
ll sum(int x, int y)
{
    ll total = 0;
    while (x != 0)
    {
        int ty = y;
        while (ty != 0)
        {
            total += tree[x][ty];
            ty -= (ty & -ty);
        }
        x -= (x & -x);
    }
    return total;
}

/* 2D Fenwick tree update operation */
void update(int x, int y, int value)
{
    while (x <= c)
    {
        int ty = y;
        while (ty <= r)
        {
            tree[x][ty] += value;
            ty += (ty & -ty);
        }
        x += (x & -x);
    }
}

/* Helper function to query 2D fenwick tree function */
ll query(int x1, int y1, int x2, int y2)
{
    return sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x2, y1 - 1) - sum(x1 - 1, y2);
}

/* */
void reset()
{
    memset(tree, 0, sizeof(tree));
    while (!q.empty())
        q.pop();
    current_cost = 0;
}


void expand(int x1, int y1, int x2, int y2)
{
    ll sum = query(x1, y1, x2, y2);

    if (sum == 0)
    {
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                q.emplace(i, j, current_cost + costs[i][j]);
                update(i, j, 1);
            }
        }
    }
    else if (sum != (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1))
    {
        int split = max(abs(x1 - x2), abs(y1 - y2));
        if (abs(x1 - x2) == split)
        {
            int mid = (x1 + x2) / 2;
            expand(x1, y1, mid, y2);
            expand(mid + 1, y1, x2, y2);
        }
        else
        {
            int mid = (y1 + y2) / 2;
            expand(x1, y1, x2, mid);
            expand(x1, mid + 1, x2, y2);
        }
    }
}

ll dijkstra(int sx, int sy, int ex, int ey)
{
    q.emplace(sx, sy, costs[sx][sy]);
    update(sx, sy, 1);
    while (!q.empty())
    {
        point v = q.top();
        q.pop();
        current_cost = v.c;
        if (v.x == ex and v.y == ey)
            return current_cost - costs[v.x][v.y];

        /* Check the borders of the box */
        int x1 = max(1, v.x - distance_x[v.x][v.y]);
        int x2 = min(c, v.x + distance_x[v.x][v.y]);
        int y1 = max(1, v.y - distance_y[v.x][v.y]);
        int y2 = min(r, v.y + distance_y[v.x][v.y]);

        expand(x1, y1, x2, y2);
    }
    return -1;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> n;

    for (int row = 1; row <= r; row++)
    {
        for (int col = 1; col <= c; col++)
        {
            cin >> costs[col][row];
        }
    }
    for (int row = 1; row <= r; row++)
    {
        for (int col = 1; col <= c; col++)
        {
            cin >> distance_y[col][row];
        }
    }
    for (int row = 1; row <= r; row++)
    {
        for (int col = 1; col <= c; col++)
        {
            cin >> distance_x[col][row];
        }
    }

    vector<pair<int, int>> trips;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        trips.emplace_back(x, y);
    }

    for (int i = 1; i < n; i++)
    {
        reset();
        cout << dijkstra(trips[i - 1].second, trips[i - 1].first, trips[i].second, trips[i].first);
        if (i != n - 1) {cout << " ";}
    }
    cout << endl;
}
