/*
Problem: https://www.spoj.com/problems/SALMAN/
Tags: Tree, DFS, LazySegmentTree
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long intt;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<intt> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

int preorder(vvi &tree, int time, int root, vpar &range, vll &preorder_salary, vll &salary)
{
    int st_sum = time;
    for (int &child : tree[root])
    {
        time = preorder(tree, time + 1, child, range, preorder_salary, salary);
    }
    range[root] = {st_sum, time};
    preorder_salary[st_sum] = salary[root];
    return time;
}

class SegTreeLazy
{
    vector<intt> arr, st_sum, st_min, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j)
        {
            st_sum[u] = arr[i];
            st_min[u] = arr[i];
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m);
        build(r, m + 1, j);
        st_sum[u] = st_sum[l] + st_sum[r];
        st_min[u] = min(st_min[l], st_min[r]);
    }

    void propagate(int u, int i, int j, intt x)
    {
        st_sum[u] += (j - i + 1) * x;
        st_min[u] += x;
        if (i != j)
        {
            lazy[u * 2 + 1] += x;
            lazy[u * 2 + 2] += x;
        }
        lazy[u] = 0;
    }

    intt query_sum(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return 0;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            return st_sum[u];
        intt x = query_sum(a, b, l, i, m);
        intt y = query_sum(a, b, r, m + 1, j);
        return x + y;
    }

    intt query_min(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return 1e18;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            return st_min[u];
        intt x = query_min(a, b, l, i, m);
        intt y = query_min(a, b, r, m + 1, j);
        return min(x, y);
    }

    void update(int a, int b, intt value,
                int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            propagate(u, i, j, value);
        else if (j < a or b < i)
            return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st_sum[u] = st_sum[l] + st_sum[r];
            st_min[u] = min(st_min[l], st_min[r]);
        }
    }

  public:
    SegTreeLazy(vector<intt> &v)
    {
        arr = v;
        n = v.size();
        st_sum.resize(n * 4 + 5);
        st_min.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    intt query(int a, int b)
    {
        return query_sum(a, b, 0, 0, n - 1);
    }

    void update(int a, int b)
    {
        intt value = min(intt(1000), query_min(a, b, 0, 0, n - 1));
        update(a, b, value, 0, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int case_number = 1;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vll salary(n);
        vvi tree(n);
        vll preorder_salary(n);
        vpar range(n);

        cout << "Case " << case_number << ":\n";
        case_number++;

        rep(i, n)
        {
            int a, b;
            cin >> a >> b;
            a--;
            salary[i] = b;
            if (a != -1)
                tree[a].emplace_back(i);
        }

        preorder(tree, 0, 0, range, preorder_salary, salary);
        SegTreeLazy stl(preorder_salary);

        while (q--)
        {
            int c, v;
            cin >> c >> v;
            v--;
            if (c == 1)
            {
                cout << stl.query(range[v].first, range[v].second) << "\n";
            }
            else
            {
                stl.update(range[v].first, range[v].second);
            }
        }
    }
}
