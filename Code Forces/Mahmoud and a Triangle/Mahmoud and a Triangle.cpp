/*
Problem: https://codeforces.com/problemset/problem/766/B
Tags: Greedy, Sorting
Status: Accepted
*/

#include <bits/stdc++.h>

int array[100000];

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{

    int n;
    std::cin >> n;

    copy_n(std::istream_iterator<int>(std::cin), n, array);

    qsort(array, n, sizeof(int), compare);

    for (int i = 0; i <= n - 3; i++)
    {
        if (array[i] + array[i + 1] > array[i + 2])
        {
            std::cout << "YES"
                      << "\n";
            return 0;
        };
    }
    std::cout << "NO"
              << "\n";
    return 0;
}