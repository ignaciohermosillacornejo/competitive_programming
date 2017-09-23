// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>

const int MAX_NODES = 9 + 1; // TODO: update number for submision
int tree[MAX_NODES][26];
int freq[MAX_NODES];
int nodes;

void init_trie() {
    memset(tree, -1, sizeof tree);
    memset(freq, 0, sizeof freq);
    nodes = 1;
}

void add_word(std::string & word) {
    int current = 0;
    freq[0]++;
    for (char c : word) {
        int & nxt = tree[current][c - 'a'];
        if (nxt == -1) nxt = nodes++;
        current = nxt;
        freq[current]++; // update node frequency
    }
}

int freq_children(int father) {
    // returns the frequency of the children
    bool leaf = true;
    for (int i = 0; i < 26; i++){
        if (tree[father][i] == -1) leaf = false;
    }
}


int main()
{
    init_trie();
    std::string s = std::string("hello");
    add_word(s);
    s = std::string("heaven");
    add_word(s);
    s = std::string("hell");





    return 0;
}