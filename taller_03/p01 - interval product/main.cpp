// segment tree implementation found on codeforces.com/blog/entry/18051
#include <bits/stdc++.h>

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build()
{
    // we build the nodes of the trees, note that for this, we must already
    // have copied the input elements to the tree from n to 2n
    for (int i = n - 1; i > 0; i--) t[i] = t[i<<1] * t[i<<1|1];
}

void update(int p, int value) // set value at position p
{
    // we iterate through the values of p, initially displacing it by n and setting the value
    // we then propagate the value till we are in the second to last layer of the segment tree
    // Note* p^1 is the same as p XOR 1, so we can use it to switch between i (even) and i + 1 (odd) easily
    if (value == 0) t[p += n] = 0;
    else if (value > 0) t[p += n] = 1;
    else t[p += n] = -1;
    for (; p > 1; p >>= 1) t[p>>1] = t[p] * t[p^1];
}

int query(int l, int r)
{  // product on interval [l, r]
    // This algorithm querys from the bottom to the top in an efficient way
    int res = 1; // We need to start with a neutral value for the operation
    for (l += n, r += (n + 1); l < r; l >>= 1, r >>= 1)
    {
        if (l&1) res *= t[l++];
        if (r&1) res *= t[--r];
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    int K;

    while(std::cin >> n >> K)
    {
        std::vector<int> sequence;
        sequence.reserve(n);
        copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(sequence));

        for (int i = 0; i < n; i++)
        {
            if (sequence[i] == 0) t[i + n] = 0;
            else if (sequence[i] > 0) t[i + n] = 1;
            else t[i + n] = -1;
        }
        build();

        while (K--)
        {
            char a;
            int l, r;
            std::cin >> a >> l >> r;
            if (a == 'C') update(l - 1, r);
            else
            {
                int res = query(l - 1, r - 1);
                if (res == 0) std::cout << "0";
                else if (res > 0) std::cout << "+";
                else std::cout << "-";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
