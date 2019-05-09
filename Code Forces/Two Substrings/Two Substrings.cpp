/*
Problem:  https://codeforces.com/problemset/problem/550/A
Tags: Brute Force, Implementation, Strings
Status: Accepted
*/

#include <bits/stdc++.h>

std::vector<char> word; // array in (array of the input)

int main()
{

    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    std::string input;

    std::cin >> input;

    int ab_ba_switch = 0; // 0 to look for AB and 1 to look for BA. -1 if it hasn't found anything

    for (int i = 0; i < input.length() - 1; i++)
    {
        if (input[i] == 'A' and input[i + 1] == 'B' and ab_ba_switch == 0)
        {
            ab_ba_switch = 1;
            i++;
        }
        else if (ab_ba_switch == 1 and input[i] == 'B' and input[i + 1] == 'A')
        {
            std::cout << "YES"
                      << "\n";
            return 0;
        }
    }
    ab_ba_switch = 0;
    for (int i = 0; i < input.length() - 1; i++)
    {
        if (input[i] == 'B' and input[i + 1] == 'A' and ab_ba_switch == 0)
        {
            ab_ba_switch = 1;
            i++;
        }
        else if (ab_ba_switch == 1 and input[i] == 'A' and input[i + 1] == 'B')
        {
            std::cout << "YES"
                      << "\n";
            return 0;
        }
    }
    std::cout << "NO"
              << "\n";

    return 0;
}