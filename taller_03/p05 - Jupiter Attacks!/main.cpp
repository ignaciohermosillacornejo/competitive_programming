// segment tree implementation found on codeforces.com/blog/entry/18051
#include <bits/stdc++.h>#include <bits/stdc++.h>

int B, P, L, N;
int t[int(2 * 1e5)];

void build()
{
    // we build the nodes of the trees, note that for this, we must already
    // have copied the input elements to the tree from n to 2n
    for (int i = L - 1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
}

void update(int p, int value) // set value at position p
{
    // we iterate through the values of p, initially displacing it by n and setting the value
    // we then propagate the value till we are in the second to last layer of the segment tree
    // Note* p^1 is the same as p XOR 1, so we can use it to switch between i (even) and i + 1 (odd) easily
    for (t[p += L - 1] = (int(std::pow(B, L - (p - (L - 1))))) % P * value % P; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r)
{
    // product on interval [l, r]
    // This algorithm querys from the bottom to the top in an efficient way
    int constant = int(std::pow(B, ((r - l)*(r - l + 1))/2));
    int res = 0; // We need to start with a neutral value for the operation
    for (l += (L - 1), r += (L + 1 - 1); l < r; l >>= 1, r >>= 1)
    {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res/constant;
}

int main()
{
    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    while(std::cin >> B >> P >> L >> N)
    {
        if (B == 0 && P == 0 && L == 0 && N == 0) return 0;

        std::fill(t, t + int(2 * 1e5), 0);

        //build();

        while (bool(N--))
        {
            char a;
            int l, r;
            std::cin >> a >> l >> r;
            if (a == 'E') update(l, r);
            else std::cout << query(l, r) << "\n";
        }
        std::cout << "-" << "\n";
    }
    return 0;
}
