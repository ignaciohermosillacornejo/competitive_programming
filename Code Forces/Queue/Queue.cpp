/*
Problem: https://codeforces.com/problemset/problem/545/D
Tags: Greedy, Implementation, Sorting
Status: Accepted
*/

#include <bits/stdc++.h>

int queue[100001];

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{

    int n;
    std::cin >> n;

    copy_n(std::istream_iterator<int>(std::cin), n, queue);

    qsort(queue, n, sizeof(int), compare);

    int happy_people = 2; // person 1 is always happy

    if (n <= 2)
    {
        std::cout << n << "\n";
        return 0;
    } // 1 or 2 people will always be happy

    // from here on down, we work assuming a queue of 3 or more people

    int total_time = queue[0] + queue[1];

    for (int i = 1; i < n;)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (queue[j] >= total_time)
            {
                total_time += queue[j];
                happy_people++;
                i = j;
                break;
            }

            i = j;
        }
    }
    std::cout << happy_people << "\n";
    return 0;
}