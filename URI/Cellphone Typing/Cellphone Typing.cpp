/*
Problem: // https://www.urionlinejudge.com.br/judge/en/problems/view/1284
Tags: Strings, Trie
Status: Accepted
*/

// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>

const int MAX_NODES = 1000000; // TODO: update number for submision
int tree[MAX_NODES][26];
int freq[MAX_NODES];
int nodes;

void reset_trie()
{
    memset(tree, -1, sizeof tree);
    memset(freq, 0, sizeof freq);
    nodes = 1;
}

void add_word(std::string &word)
{
    int current = 0;
    freq[0]++;
    for (char c : word)
    {
        int &nxt = tree[current][c - 'a'];
        if (nxt == -1)
            nxt = nodes++;
        current = nxt;
        freq[current]++; // update node frequency
    }
}

int freq_node(int father)
{
    // returns the frequency of the current node
    int n_father = father;
    int f_father = freq[father];
    int f_total = 0;
    bool leaf = true;

    for (int i = 0; i < 26; i++)
    {
        int n_child = tree[father][i];
        if (n_child != -1)
        {
            if (f_father != freq[n_child] and leaf)
                f_total += f_father;
            leaf = false;
            f_total += freq_node(n_child);
        }
    }
    if (leaf)
        return 1;
    return f_total;
}

int main()
{
    std::ios::sync_with_stdio(false); // makes cin/cout as fast as fscan and printf

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    int n;

    while (std::cin >> n)
    {
        reset_trie();
        float total = 0;
        while (n--)
        {
            std::string s;
            std::cin >> s;
            add_word(s);
        }
        for (int i = 0; i < 26; i++)
        {
            if (tree[0][i] != -1)
                total += freq_node(tree[0][i]);
        }
        std::cout << total / float(freq[0]) << "\n";
    }

    return 0;
}