/*
Problem: https://www.spoj.com/problems/PRINT/
Tags: Math, Primes, Sieve Of Eratosthenes, Segmented Sieve Of Eratosthenes
Status: Accepted
*/

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

const int64_t L1D_CACHE_SIZE = 32768*8;

vi sieve(int n)
{
    vi primes;

    vector<bool> is_prime(n + 1, true);
    int limit = (int)floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;

    repx(i, 2, n + 1) if (is_prime[i]) primes.eb(i);

    return primes;
}

int main()
{
    // fast IO
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    // generate all primes until sqrt(2^31)
    vi low_primes = sieve(46341);

    rep(test_case, t)
    {
        int low, high;
        cin >> low >> high;

        low = max(2, low);
        high = max(2, high);

        vector<bool> high_primes(high - low + 1, true);

        for (auto prime : low_primes)
        {
            if (prime > high) continue;

            int low_bound = floor(low/prime) * prime;

            if (low_bound < low) low_bound += prime;


            for (int j= low_bound; j <= high; j += prime)
            {
                high_primes[j - low] = false;
            }

            if (low_bound == prime)
            {
                high_primes[low_bound - low] = true;
            }
        }

        for (int i = low; i <= high; i++)
        {
            if (high_primes[i - low])
                cout << i << "\n";
        }
    }
}