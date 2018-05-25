#include <bits/stdc++.h>

int n;
int t;

int main()
{
    std::cin >> n >> t;
    if (n == 1 and t == 10)
    {
        std::cout << -1;
    }
    else if (t == 10)
    {
        std::cout << 1;
        n--;
        while(n--)
        {
            std::cout << 0;
        }
    }
    else 
    {
        while(n--)
        {
            std::cout << t;
        }
    }
    std::cout << "\n";
}