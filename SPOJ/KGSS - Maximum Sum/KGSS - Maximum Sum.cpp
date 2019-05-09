/*
Problem: https://www.spoj.com/problems/KGSS/
Tags: Tree, SegmentTree
Status: Accepted
*/

#include <bits/stdc++.h>#include <bits/stdc++.h>

const int N = 10e7; // limit for array size
int n;              // array size
int t[2 * N];
int s[2 * N];
//int array[16] = {7, 6, 2, 1, 20, 60, 11, 21, 7, 8, 2, 7, 6, 0, 5, 11};
//int array[5] = {1, 2, 3, 4, 5};

void build()
{
    // we build the nodes of the trees, note that for this, we must already
    // have copied the input elements to the tree from n to 2n
    for (int i = n - 1; i > 0; i--)
        t[i] = std::max(t[i << 1], t[i << 1 | 1]);
    // we create the first layer of the s min array (1 layer above the leafs)
    for (int i = n - 1; i > (n - 1) >> 1; i--)
        s[i] = std::min(s[i << 1], s[i << 1 | 1]);
    // we create the remaining layers of the s min array, taking the second highest value
    // from the 4 nodes (two child nodes on each tree)
    for (int i = ((n - 1) >> 1); i > 0; i--)
    {
        int s_max_array[4] = {t[i << 1], t[i << 1 | 1], s[i << 1], s[i << 1 | 1]};
        std::sort(std::begin(s_max_array), std::end(s_max_array)); // Asc sort
        s[i] = s_max_array[2];                                     // We have 4 elements, 2 is the second to last element
    }
}

void update(int p, int value) // set value at position p
{
    p += (n - 1);

    for (t[p] = value, s[p] = value, p >>= 1; p > 0; p >>= 1)
    {
        t[p] = std::max(t[p << 1], t[p << 1 ^ 1]);
        if (p > (n - 1) >> 1)
            s[p] = std::min(s[p << 1], s[p << 1 ^ 1]);
        else
        {
            int s_max_array[4] = {t[p << 1], t[p << 1 ^ 1], s[p << 1], s[p << 1 ^ 1]};
            std::sort(std::begin(s_max_array), std::end(s_max_array));
            s[p] = s_max_array[2];
        }
    }
}

int query_max(int l, int r)
{ // greatest possible sum on interval [l, r]
    // This algorithm query's from the bottom to the top in an efficient way
    int max = 0; // We need to start with a neutral value for the operation
    // IDEA, we are looking for the greatest possible sum between two digits in the range
    // we have stored the first_max, so its a matter of finding the greatest and second greatest
    // such that their indexes are different
    for (l += (n - 1), r += (n + 1 - 1); l < r; l >>= 1, r >>= 1)
    {
        if (bool(l & 1))
            max = std::max(t[l++], max);
        if (bool(r & 1))
            max = std::max(t[--r], max);
    }
    return max;
}

int query_second_max(int l, int r)
// second_highest value on interval [l, r]
{
    std::vector<int> posibleValues;
    for (l += (n - 1), r += (n + 1 - 1); l < r; l >>= 1, r >>= 1)
    {
        if (bool(l & 1))
        {
            if (r >= n)
                posibleValues.push_back(t[l++]);
            else
            {
                posibleValues.push_back(t[l]);
                posibleValues.push_back(s[l++]);
            }
        }
        if (bool(r & 1))
            if (r >= n)
                posibleValues.push_back(t[--r]);
            else
            {
                posibleValues.push_back(t[--r]);
                posibleValues.push_back(s[r]);
            }
    }
    std::sort(std::rbegin(posibleValues), std::rend(posibleValues)); // Sort candidates from greatest to smallest
    return posibleValues[1];
}

int nextPow2(int n)
{
    if (n <= 1)
        return n;
    double d = n - 1;
    return 1 << ((((int *)&d)[1] >> 20) - 1022);
}

int main()
{
    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    std::cin >> n;
    //n = 5;

    std::vector<int> sequence;
    sequence.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(sequence));

    //std::cout << n << "\n";

    //std::cout << "derp" << "\n";
    n = nextPow2(n);

    for (int i = 0; i < sequence.size(); i++)
    {
        t[i + n] = sequence[i]; // array[i];
        s[i + n] = sequence[i]; // array[i];
    }

    build();

    int K;
    std::cin >> K;
    //int K = -1;

    //std::cout << query_max(2, 4) << " " << query_second_max(2, 4) << "\n";
    //std::cout << query_max(2, 5) << " " << query_second_max(2, 5) << "\n";

    // 7, 9, 11, 12

    while (K--)
    {
        char a;
        int l, r;
        std::cin >> a >> l >> r;
        if (a == 'U')
            update(l, r);

        else
        {
            //std::cout << query_max(l, r) << " " << query_second_max(l, r) << "\n";
            std::cout << query_max(l, r) + query_second_max(l, r) << "\n";
        }
    }

    return 0;
}
