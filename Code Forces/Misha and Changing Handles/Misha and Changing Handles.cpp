/*
Problem: https://codeforces.com/problemset/problem/501/B?csrf_token=fc1e38aae0000e393a65024e60f3a192
Tags: Union Find
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

//typedef long long ll;
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define umap unordered_map
#define uset unordered_set

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)                                                         \
    cerr << #m << endl;                                                    \
    rep(i, (int)m.size())                                                  \
    {                                                                      \
        cerr << i << ":";                                                  \
        rep(j, (int)m[i].size())                                           \
        {                                                                  \
            cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        }                                                                  \
        cerr << endl;                                                      \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

#endif

int findSet(vi &p, int i)
{
    return (p[i] == i) ? i : (p[i] = findSet(p, p[i]));
}
bool isSameSet(vi &p, int i, int j)
{
    return findSet(p, i) == findSet(p, j);
}
void UnionSet(vi &p, int i, int j)
{
    if (not isSameSet(p, i, j))
    {
        int x = findSet(p, i), y = findSet(p, j);
        p[x] = y;
    }
}

bool find_key(map<string, int> h, string k)
{
    if (h.find(k) != h.end())
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int pos = 0;
    map<string, int> names;
    map<int, string> reversed_names;
    vi p(2 * n);
    rep(i, 2 * n)
        p[i] = i;

    rep(i, n)
    {
        string a, b;
        cin >> a >> b;
        int x;
        int y;

        if (find_key(names, a))
            x = names[a];
        else
        {
            x = pos;
            names[a] = pos;
            reversed_names[x] = a;
            pos++;
        }

        y = pos;
        pos++;
        names[b] = y;
        reversed_names[y] = b;
        UnionSet(p, x, y);
    }

    int changing_users = 0;
    vector<bool> counted(n, false);
    rep(i, pos) if (not counted[findSet(p, i)])
    {
        counted[findSet(p, i)] = true;
        changing_users += 1;
    }

    cout << changing_users << "\n";
    vector<bool> printed(n, false);
    rep(i, pos)
    {
        int current = findSet(p, i);
        if (not printed[current])
        {
            printed[current] = true;
            cout << reversed_names[i] << " " << reversed_names[current] << "\n";
        }
    }
}