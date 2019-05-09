/*
Problem: https://codeforces.com/contest/777/problem/A
Tags: Implementation
Status: Accepted
*/

#include <bits/stdc++.h>

int main()
{
    int n;
    int x;
    std::cin >> n;
    std::cin >> x;

    n = n % 6;
    while (n != 0)
    {

        if (n % 2 == 0)
        {
            if (x == 2)
                x = 1;
            else if (x == 1)
                x = 2;
        }
        else
        {
            if (x == 1)
                x = 0;
            else if (x == 0)
                x = 1;
        }
        n--;
    }

    std::cout << x << "\n";
}