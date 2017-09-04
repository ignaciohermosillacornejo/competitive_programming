#include <bits/stdc++.h>

int max_value = 1000000 + 5; //  10**6
long long int tree[1000000 + 5]; // 10**6 + 1 (0 doesn't count)

long long int sum(int index)
{
    long long int total = 0;
    while(index != 0)
    {
        total += tree[index];
        index -= (index & -index);
    }
    return total;
}

void update(int index, int value)
{
    while(index <= max_value)
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
    int N; std::cin >> N;
    std::vector<int> sequence; sequence.reserve(N);
    copy_n(std::istream_iterator<int>(std::cin), N, back_inserter(sequence));
    for (int i = 1; i <= N; i++) { update(i, sequence[i-1]);}

    int Q; std::cin >> Q >> std::ws; // we read Q, note that std::ws ignores '\n'

    // we execute the actions, either printing the sums of the range, or updating the tree
    while (Q--){
        char o; int l; int r; std::cin >> o >> l >> r;
        if (o == 'q') {std::cout << sum(r) - sum(l-1) << "\n";}
        else {update(l, r);}
    }
}
