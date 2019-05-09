/*
Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
Tags: Tree, LazySegmentTree
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

class SegTreeLazy
{
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
        st[u] = st[l] + st[r];
    }

    intt flip(intt u)
    {
        if (lazy[u] == 0)
            return 3; // nothing with a flip turns into a flip
        if (lazy[u] == 1)
            return 2; // a flip of a set 1 turns into a set 0
        if (lazy[u] == 2)
            return 1; // a flip of a set 0 turns into a set 1
        if (lazy[u] == 3)
            return 0; // a flip + flip turns into nothing
    }

    void propagate(int u, int i, int j, intt x)
    {
        if (x == 0)
            return; // nothing to propagate
        if (x == 1) // set the positions with 1
            st[u] = (j - i + 1);
        else if (x == 2) // set the positions with 0
            st[u] = 0;
        else
            st[u] = (j - i + 1) - st[u];
        if (i != j)
        {
            int l = u * 2 + 1;
            int r = u * 2 + 2;
            if (x == 3)
            {
                lazy[l] = flip(l);
                lazy[r] = flip(r);
            }
            else
            {
                lazy[l] = x;
                lazy[r] = x;
            }
        }
        lazy[u] = 0;
    }

    intt query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) // out of range
            return 0;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        propagate(u, i, j, lazy[u]); // we push the value down, regardless of the state
        if (a <= i and j <= b)       // our node range is inside our query, we return our node value
            return st[u];
        intt x = query(a, b, l, i, m);
        intt y = query(a, b, r, m + 1, j);
        return x + y;
    }

    void update(int a, int b, intt value,
                int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b)
            propagate(u, i, j, value);
        else if (j < a or b < i)
            return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = st[l] + st[r];
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    int case_count = 1;
    while (T--)
    {
        cout << "Case " << case_count << ":\n";
        case_count++;
        vll pirates;
        int m;
        cin >> m;
        while (m--)
        {
            int a;
            cin >> a;
            string p;
            cin >> p;
            while (a--)
            {
                for (char &c : p)
                {
                    if (c == '1')
                        pirates.eb(1);
                    else
                        pirates.eb(0);
                }
            }
        }
        SegTreeLazy sgtl(pirates);
        int q;
        cin >> q;
        int count_query = 1;
        while (q--)
        {
            char c;
            int a;
            int b;
            cin >> c >> a >> b;
            if (c == 'F')
                sgtl.update(a, b, 1);
            else if (c == 'E')
                sgtl.update(a, b, 2);
            else if (c == 'I')
                sgtl.update(a, b, 3);
            else if (c == 'S')
            {
                cout << "Q" << count_query << ": " << sgtl.query(a, b) << "\n";
                count_query++;
            }
        }
    }
}
