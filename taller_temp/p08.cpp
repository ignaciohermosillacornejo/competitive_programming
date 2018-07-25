#include <bits/stdc++.h>

int max_value = 1000000 + 5;     //  10**6
long long int tree[1000000 + 5]; // 10**6 + 1 (0 doesn't count)

long long int sum(int index)
{
    long long int max = 0;
    while (index != 0)
    {
        max = std::max(max, tree[index]);
        index -= (index & -index);
    }
    return max;
}

void update(int index, int value)
{
    while (index <= max_value)
    {
        tree[index] += value;
        index += (index & -index);
    }
}

int main()
{
    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    // we read our array and load it into the tree, we do that by first copying the input into a vector
    // and then iterating over the vector and inputing the values to the tree
    int N;
    std::cin >> N;
    std::vector<int> sequence;
    sequence.reserve(N);
    copy_n(std::istream_iterator< std::tuple<int, int, int> >(std::cin), N, back_inserter(sequence));

    
}