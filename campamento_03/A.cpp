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

struct MAX
{
    static int const neutro = INT_MIN;
    static int op(intt x, intt y)
    {
        return max(x, y);
    }
};

struct MIN
{
    static int const neutro = INT_MAX;
    static int op(intt x, intt y)
    {
        return min(x, y);
    }
};

template <class t> class ST
{
    vi tree;
    int n;

    public:
       ST(vi &arr)
        {
            n = arr.size();
            tree.resize(2 * n);
            // insert leaf nodes in tree
            for (int i = 0; i < n; i++)
                tree[n + i] = arr[i];
            // build the tree by calculating parents
            for (int i = n - 1; i > 0; --i)
                tree[i] = t::op(tree[i << 1], tree[i << 1 | 1]);

        }

        // function to get sum on interval [l, r]
        int query(int l, int r)
        {
            r++; // so that we get [l, r] instead of [l, r)
            int res = t::neutro;
            // loop to find the sum in the range
            for (l += n, r += n; l < r; l >>= 1, r >>= 1)
            {
                if (l & 1)
                    res = t::op(res, tree[l++]);
                if (r & 1)
                    res = t::op(res, tree[--r]);
            }
            return res;
        }
};

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n;
        cin >> n;
        vi array_min(n);
        vi array_max(n);

        rep(i, n)
        {
            int x;
            cin >> x;
            array_max[i] = x;
        }
        rep(i, n)
        {
            int x;
            cin >> x;
            array_min[i] = x;
        }

        ST<MAX> st_max(array_max);
        ST<MIN> st_min(array_min);


        intt count = 0;
        rep(i, n)
        {
            if (array_max[i] > array_min[i])
                continue; // we skip this i

            // binary search
            int l = i, r = n - 1;
            int start = -1, end = -1;

            while (l <= r)
            {
                int m = l + r >> 1;

                // target found, we discard the right (we are looking for the first ocurrence)
                if (st_max.query(i, m) == st_min.query(i, m))
                {
                    start = m;
                    r = m - 1;
                } // we discard the right half
                else if (st_max.query(i, m) > st_min.query(i, m))
                    r = m - 1;
                else // we discard the left half
                    l = m + 1;
            }

            l = i;
            r = n - 1;
            while (l <= r)
            {
                int m = l + r >> 1;

                // target found, we discard the left (we are looking for the last ocurrence)
                if (st_max.query(i, m) == st_min.query(i, m))
                {
                    end = m;
                    l = m + 1;
                } // we discard the right half
                else if (st_max.query(i, m) > st_min.query(i, m))
                    r = m - 1;
                else // we discard the left half
                    l = m + 1;
            }

            //cout << "i: " << i << " start: " << start << " end: " << end << "\n";
            if (start > -1)
                count += (end - start + 1);
        }
        cout << count << "\n";
}