/*
Problem: https://codeforces.com/problemset/problem/230/B
Tags: Binary Search, Number Theory, Math, Implementation
Status: Accepted
*/

#include <bits/stdc++.h>

int main()
{

    long long length;
    std::cin >> length;
    long long int max_number;
    max_number = 0;

    std::vector<long long int> sequence;
    sequence.reserve(length);

    std::copy_n(std::istream_iterator<long long int>(std::cin), length, back_inserter(sequence));

    for (long long int i = 0; i < length; i++)
    {
        if (sequence.at(i) > max_number)
        {
            max_number = sequence.at(i);
        }
    }
    long long int square = (long long int)std::sqrt(max_number);

    bool prime[square + 1];
    memset(prime, true, sizeof(prime));

    for (long long int p = 2; p * p <= square; p++)
    {
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (long long int i = p * 2; i <= square; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (long long int i = 0; i < length; i++)
    {
        if (sequence.at(i) == 1)
        {
            std::cout << "NO"
                      << "\n";
        }
        else
        {
            long long int root = (long long int)std::sqrt(sequence.at(i));
            //std::cout << root << "\n";
            //std::cout << sequence.at(i) << "\n";
            //std::cout << prime[root] << "\n";
            if (root * root == sequence.at(i) and prime[root] == true)
            {
                std::cout << "YES"
                          << "\n";
            }
            else
            {
                std::cout << "NO"
                          << "\n";
            }
        }
    }
}