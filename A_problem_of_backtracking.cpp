#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (size_t i = 0; i < (size_t)n; i++)
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

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

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
vector<int> wheights;
vector<int> solution;
int k;

bool solver(int pos, int mask, long long accum_sum)
{
    if (accum_sum > k) return false;
    if (mask == 1024 - 1) return true;

    for (int i = 0, b = 1; i < 10; i++, b<<=1)
    {
        if ((mask & b) == 0)
        {
            if (solver(pos + 1, mask | b, accum_sum + wheights[pos] * i))
            {
                solution.emplace_back(i); // append en python
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i = i + 1)
    {
        wheights.empty();
        wheights.assign(10, -1);

        solution.clear();

        for (int j = 0; j < 10; j++)
        {
            int aux;
            cin >> aux;
            wheights[j] = aux;
        }
        cin >> k;

        solver(0, 0, 0);

        reverse(solution.begin(), solution.end());

        for (int j = 0; j < solution.size(); j++)
        {
            if (j > 0) cout << " ";
            cout << solution[j];
        }
        if (solution.size() == 0)
            cout << "-1";
        cout << "\n";
    }
}