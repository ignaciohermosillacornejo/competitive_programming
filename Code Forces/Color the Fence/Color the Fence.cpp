/*
Problem: https://codeforces.com/problemset/problem/349/B
Tags: DP, Greedy
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long paint_left;
    std::cin >> paint_left;
    long long og_paint = paint_left;
    std::vector<long long int> sequence;
    sequence.reserve(9);
    std::copy_n(std::istream_iterator<long long int>(std::cin), 9, back_inserter(sequence));

    int pos = 0;
    for (int i = 0; i < 9; i++)
    {
        if (sequence[i] <= paint_left and sequence[i] <= sequence[pos])
        {
            pos = i;
            // cout << sequence[i] << endl;
        }
    }
    vector<int> fence_number;

    while (paint_left >= sequence[pos])
    {
        fence_number.push_back(pos + 1);
        paint_left -= sequence[pos];
    }

    if (paint_left == og_paint)
    {
        cout << -1 << endl;
    }
    else // TODO: change to recursive implementation
    {
        int l_pos = 0;
        int r_pos = 8;
        while (pos < r_pos)
        {
            if (paint_left + sequence[pos] >= sequence[r_pos])
            {
                fence_number[l_pos] = r_pos + 1;
                paint_left = paint_left + sequence[pos] - sequence[r_pos];
                l_pos += 1;
            }
            else
            {
                r_pos -= 1;
            }
        }
        for (const auto &i : fence_number)
        {
            cout << i;
        }
        cout << endl;
    }
}