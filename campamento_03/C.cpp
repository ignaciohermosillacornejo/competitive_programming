#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> graph;
typedef vector<vector<par>> wgraph;

struct FenwickTree
{
    vector<int> FT;
    FenwickTree(int N)
    {
        FT.resize(N + 1, 0);
    }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j)
    {
        return query(j) - query(i - 1);
    }

    void update(int i, int v)
    {
        int s = query(i,i);
        //cout << FT[i] << "\n";
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v-s;
    }

    //Queries puntuales, Updates por rango
    void update(int i, int j, int v)
    {
        update(i, v);
        update(j + 1, -v);
    }

    void printFT();
};


int main()
{
    int n;
    int case_n = 1;
    bool flag = true;
    while(cin >> n)
    {
        if (n == 0) return 0;
        if (not flag) cout << "\n"; flag = false;
        FenwickTree ft(n);
        cout << "Case " << case_n << ":\n"; case_n++;
        for (int i = 1; i <= n; ++i)
        {
            int v; cin >> v;
            ft.update(i, v);
        }
        string action;
        while(cin >> action)
        {
            if (action == "END") break;
            else if (action == "S")
            {
                int i; int v;
                cin >> i >> v;
                ft.update(i, v);
            }
            else
            {
                int i; int j;
                cin >> i >> j;
                cout << ft.query(i, j) << "\n";
            }
        }
    }
}