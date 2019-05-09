/*
Problem: https://codeforces.com/problemset/problem/277/A
Tags: Graph, UnionFind
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
typedef vector<int> vi;
typedef pair<ll, ll> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

class UnionFind
{
  private:
    vi p, rank, setSize;
    int numSets;

  public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vi lang(m, 0);
    int iliterate = 0;
    UnionFind u(m);
    rep(i, n)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            iliterate++;
            continue;
        }
        int a;
        cin >> a;
        a--;
        int last = a;
        lang[a] = 1;
        rep(j, k - 1)
        {
            cin >> a;
            a--;
            lang[a] = 1;
            u.unionSet(last, a);
        }
    }
    int rest = 0;
    rep(i, m)
    {
        if (lang[i] == 0)
            rest++;
    }
    cout << u.numDisjointSets() + iliterate - rest - (iliterate != n) << endl;
}