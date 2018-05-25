#include <bits/stdc++.h>

using namespace std;
int n;
int t[2 * (100000 + 1)];


void build()
{
    // we build the nodes of the trees, note that for this, we must already
    // have copied the input elements to the tree from n to 2n
    for (int i = n - 1; i > 0; i--) t[i] = min(t[i<<1],t[i<<1|1]);
}

void update(int p, int value) // set value at position p
{
    // we iterate through the values of p, initially displacing it by n and setting the value
    // we then propagate the value till we are in the second to last layer of the segment tree
    // Note* p^1 is the same as p XOR 1, so we can use it to switch between i (even) and i + 1 (odd) easily
    if (value == 0) t[p += n] = 0;
    else if (value > 0) t[p += n] = 1;
    else t[p += n] = -1;
    for (; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r)
{  // min on interval [l, r]
    // This algorithm querys from the bottom to the top in an efficient way
    int res = INT16_MAX; // We need to start with a neutral value for the operation
    for (l += n, r += (n + 1); l < r; l >>= 1, r >>= 1)
    {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(res, t[--r]);
    }
    return res;
}


int main(){


    n = 5;
    for (int i = 0; i < n; i++){
        t[n + i] = i;
    }

    build();

    for (int i = 1; i <= n*2; i++){
        cout << i << ": " << t[i] << endl;
    }

    cout << query(1, 4) << endl; 
}