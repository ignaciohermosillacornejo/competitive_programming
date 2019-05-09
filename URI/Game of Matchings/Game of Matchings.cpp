/*
Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2350
Tags: Strings
Status: TLE
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

bool find_match(string &s, vi &pattern, int position)
{
    vector<bool> available_numbers(27, true);
    vector<char> matches(27, '0');
    for (int i = 0; i < pattern.size(); i++)
    {
        int c = s[position + i] - 'a';
        int p = pattern[i];

        if (matches[c] == '0' and available_numbers[p]) // never used before
        {
            matches[c] = p;
            available_numbers[p] = false;
        }
        else if (matches[c] == p)
            continue;
        else
            return false;
    }
    return true;
}

int count_matchings(string &s, vi &pattern)
{
    int count = 0;

    for (int i = 0; i < s.size() - pattern.size() + 1; i++)
    {
        //cout << "match @i: " << i << "\n";
        if (find_match(s, pattern, i))
            count++;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    string s;
    while (cin >> s)
    {
        int n;
        cin >> n;
        vi pattern(n);
        rep(i, n)
        {
            cin >> pattern[i];
        }
        cout << count_matchings(s, pattern) << "\n";
    }
    return 0;
}
