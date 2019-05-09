/*
Problem: https://codeforces.com/problemset/problem/665/E
Tags: Strings, Trie
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long long intt;
typedef vector<int> vi;
typedef pair<ll, ll> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

struct Trie
{
    vector<pair<int, int>> nodes;
    int next;
    vi count;
    int COMP;

    Trie(int COMP) : COMP(COMP)
    {
        nodes.reserve(1e7);
        nodes.eb(-1, -1);
        next = 1;
        count.reserve(1e7);
        count.eb(0);
    }

    void build(int s)
    {
        int i = 0;
        int v = 0;
        while (i < 30)
        {
            count[v]++;
            int nv = (s & (1 << (29 - i))) != 0 ? nodes[v].first : nodes[v].second;
            if (nv == -1)
            {
                nodes.eb(-1, -1);
                if ((s & (1 << (29 - i))) != 0)
                    nodes[v].first = next;
                else
                    nodes[v].second = next;
                v = next;
                count.eb(0);
                i++;
                next++;
            }
            else
            {
                v = nv;
                i++;
            }
        }
        count[v]++;
    }

    intt good_ammount(int s)
    {
        int i = 0;
        int v = 0;
        intt amm = 0;
        while (i < 30)
        {
            int one = ((s & (1 << (29 - i))) != 0) ? nodes[v].second : nodes[v].first;
            int zero = ((s & (1 << (29 - i))) != 0) ? nodes[v].first : nodes[v].second;
            if ((COMP & (1 << (29 - i))) == 0)
            {
                if (one != -1)
                    amm += count[one];
                if (zero != -1)
                {
                    i++;
                    v = zero;
                    if (i == 30)
                        amm += count[v];
                }
                else
                    break;
            }
            else
            {
                if (one != -1)
                {
                    i++;
                    v = one;
                    if (i == 30)
                        amm += count[v];
                }
                else
                    break;
            }
        }
        //delete dis
        i = v = 0;
        while (i < 30)
        {
            count[v]--;
            v = (s & (1 << (29 - i))) != 0 ? nodes[v].first : nodes[v].second;
            i++;
        }
        count[v]--;
        return amm;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    Trie trie(k);
    vi a(n + 1);
    a[0] = 0;
    trie.build(0);
    rep(i, n)
    {
        cin >> a[i + 1];
        a[i + 1] ^= a[i];
        trie.build(a[i + 1]);
    }
    intt sum = 0;
    rep(i, n + 1)
    {
        sum += trie.good_ammount(a[i]);
    }
    cout << sum << '\n';
}