/*
Problem: https://codeforces.com/problemset/problem/271/A
Tags: Brute Force
Status: Accepted
*/

#include <bits/stdc++.h>

bool disctintDigits(int number)
{

    int d1 = number % 10;
    number = number / 10;
    int d2 = number % 10;
    number = number / 10;
    int d3 = number % 10;
    number = number / 10;
    int d4 = number % 10;
    number = number / 10;
    //std::cout << d1 << "\n" << d2 << "\n" << d3 << "\n" << d4 << "\n";
    if (d1 != d2 and d1 != d3 and d1 != d4 and d2 != d3 and d2 != d4 and d3 != d4)
    {
        return false;
    }
    return true;
}

int main()
{
    // create the graph given in above fugure
    int Y;

    std::cin >> Y;

    Y++;

    while (disctintDigits(Y))
    {
        Y++;
    }
    std::cout << Y << "\n";

    return 0;
}