#include <bits/stdc++.h>

int a;
int b;
int c;
int dp[4000 + 1];

int main()
{
    int n; int a; int b; int c;
    std::cin >> n >> a >> b >> c;
    std::fill(dp, dp + 4000 + 1, INT16_MIN);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (i - a >= 0)
        {
            dp[i] = dp[i - a] + 1;
        }
        if (i - b >= 0 and dp[i - b] + 1 > dp[i])
        {
            dp[i] = dp[i - b] + 1;
        }
        if (i - c >= 0 and dp[i -c] + 1 > dp[i])
        {
            dp[i] = dp[i - c] + 1;
        }
    }
    std::cout << dp[n] << "\n";
}