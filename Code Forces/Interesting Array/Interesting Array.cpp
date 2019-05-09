/*
Problem: https://codeforces.com/problemset/problem/482/B
Tags: Tree, SegmentTree, LazySegmentTree
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long intt;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<vector<int>> graph;
typedef vector<vector<par>> wgraph;

struct ORQ
{
    static intt const neutro = 0;
    static intt op(intt x, intt y)
    {
        return x | y;
    }
    static intt
    lazy_op(int i, int j, intt x)
    {
        return x;
    }
};

template <class t>
class SegTreeLazy
{
  public:
    vector<intt> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j)
        {
            st[u] = arr[i];
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m);
        build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, intt x)
    {
        st[u] = t::op(st[u], t::lazy_op(i, j, x));
        if (i != j)
        {
            lazy[u * 2 + 1] = t::op(lazy[u * 2 + 1], x);
            lazy[u * 2 + 2] = t::op(lazy[u * 2 + 2], x);
        }
        lazy[u] = 0;
    }

    intt query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            return st[u];
        intt x = query(a, b, l, i, m);
        intt y = query(a, b, r, m + 1, j);
        return t::op(x, y);
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
            st[u] = t::op(st[l], st[r]);
        }
    }

  public:
    SegTreeLazy(vector<intt> &v)
    {
        arr = v;
        n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }
    intt query(int a, int b)
    {
        return query(a, b, 0, 0, n - 1);
    }

    void update(int a, int b, intt value)
    {
        update(a, b, value, 0, 0, n - 1);
    }
};
struct ANDQ
{
    intt value;
    ANDQ() { value = -1ll; }
    ANDQ(intt x) { value = x; }
    ANDQ(const ANDQ &a,
         const ANDQ &b)
    {
        value = a.value & b.value;
    }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

  public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }

    // 0-indexed
    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = node(t[p], t[p ^ 1]);
    }

    // inclusive exclusive, 0-indexed
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansl = node(ansl, t[l++]);
            if (r & 1)
                ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<intt> array(n, 0);
    vector<int> l(m);
    vector<int> r(m);
    vector<intt> q(m);
    SegTreeLazy<ORQ> tree(array);
    rep(i, m)
    {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
        r[i]--;
        tree.update(l[i], r[i], q[i]);
    }
    vector<ANDQ> arr2(n);
    rep(i, n)
    {
        arr2[i].value = tree.query(i, i);
    }
    ST<ANDQ> tree_2(arr2);
    rep(i, m)
    {
        if (q[i] != tree_2.query(l[i], r[i] + 1).value)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    rep(i, n)
    {
        cout << arr2[i].value;
        if (i != n - 1)
            cout << " ";
        else
            cout << "\n";
    }
}
