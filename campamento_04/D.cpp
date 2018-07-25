#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define eb emplace_back

typedef long long intt;
typedef vector<intt> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<vvi> igraph;

int main()
{
    int n;
    while (cin >> n)
    {
        vi a(n + 1);
        rep(i, n) cin >> a[i + 1];
        a[0] = 1e9;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        if (a[1] > n - 1)
        {
            cout << "impossivel" << endl;
            continue;
        }
        vi pos(n);
        vi partsum(n + 1, 0);
        int last = n;
        rep(i, n)
        {
            partsum[i + 1] = partsum[i] + a[i + 1];
        }
        if (partsum[n] % 2 == 1 || partsum[n] > (1ll * n) * (1ll * n - 1ll))
        {
            cout << "impossivel" << endl;
            continue;
        }
        rep(i, n)
        {
            while (a[last] <= i && last >= 0)
                if (--last == -1)
                    break;
            pos[i] = last + 1;
        }
        bool check = true;
        /*
        rep(i,n + 1) cout<<a[i]<<" ";cout<<endl;
        rep(i,n + 1) cout<<partsum[i]<<" ";cout<<endl;
        rep(i,n) cout<<pos[i]<<" ";cout<<endl;
        */
        repx(k, 1, n)
        {
            intt S = partsum[k];
            int minpos = pos[k];
            intt leftsum = (1ll * k) * (1ll * k - 1ll) + partsum[n] - partsum[max(k, minpos - 1)];
            //cout<<k<<" "<<minpos<<endl;
            if (minpos > k)
            {
                leftsum += (1ll * k) * (1ll * minpos - 1ll * k - 1ll);
            }
            if (S > leftsum)
            {
                check = false;
                break;
            }
        }
        if (check)
            cout << "possivel" << endl;
        else
            cout << "impossivel" << endl;
    }
}