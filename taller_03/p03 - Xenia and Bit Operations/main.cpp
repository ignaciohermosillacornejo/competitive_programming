// segment tree implementation found on codeforces.com/blog/entry/18051
#include <bits/stdc++.h>#include <bits/stdc++.h>


const int N = 131072 + 1;  // limit for array size
int n;  // array size
int t[2 * N];
//int array[8] = {1,2,3,4,5,6,7,8};


void build()
{
    // we build the nodes of the trees, note that for this, we must already
    // have copied the input elements to the tree from n to 2n
    int i = n - 1;
    int size_of_layer = n>>1; // size of layer 1
    int operation_switch = 1; // 1 is OR, 0 is XOR
    while (i > 0)
    {
        if (i < size_of_layer)
        {
            operation_switch^=1;
            size_of_layer >>= 1;
        }
        if (bool(operation_switch)) t[i] = (t[i<<1]|t[i<<1|1]); // Bitwise OR
        else t[i] = (t[i<<1]^t[i<<1|1]); // Bitwise XOR
        i--;
    }
}

void update(int p, int value) // set value at position p
{
    p += (n - 1);
    int operation_switch = 1; // 1 is OR, 0 is XOR
    for (t[p] = value; p > 1; p >>= 1)
    {
        if(bool(operation_switch)) t[p>>1] = (t[p]|t[p^1]);
        else t[p>>1] = (t[p]^t[p^1]);
        operation_switch^=1;
    }
}

int query() {  // result of operations on values [l, r]
    return t[1];
}

int main() {
    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    int K;
    std::cin >> n >> K;

    n = int(std::pow(2, n));

    std::vector<int> sequence;
    sequence.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(sequence));

    for (int i = 0; i < n; i++)
    {
        t[i + n] = sequence[i]; // array[i];
    }
    build();

    while (bool(K--))
    {
        int p, v;
        std::cin >> p >> v;
        update(p, v);
        std::cout << query() << "\n";
    }

    return 0;
}


