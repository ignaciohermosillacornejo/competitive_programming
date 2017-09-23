#include <bits/stdc++.h>

int main()
{
    int m,n;
    std::cin >> m >> n;
    int count = 0;
    while(m > 0 or n > 0)
    {
        if (m == 0 or n == 0) break;
        if ((m == 1 and n >= 2) or (n == 1 and m >= 2)) { m--; n--; count++; break; };
        if (m == 1 and n == 1) break;
        if (m >= n) { m -= 2; n--; count++; }
        else { m--; n -= 2; count++; };
    }
    std::cout << count << "\n";
    return 0;
}