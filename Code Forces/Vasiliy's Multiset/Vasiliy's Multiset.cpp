/*
Problem: https://codeforces.com/problemset/problem/706/D
Tags: Strings, Trie
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

/* Implementation from: https://pastebin.com/fyqsH65k */
struct TrieNode
{
    int leaf;   // number of words that end on a TrieNode (allows for duplicate words)
    int height; // height of a TrieNode, root starts at height = 1, can be changed with the default value of constructor
    // number of words that pass through this node,
    // ask root node for this count to find the number of entries on the whole Trie
    // all nodes have 1 as they count the words than end on themselves (ie leaf nodes count themselves)
    int count;
    TrieNode *parent; // pointer to parent TrieNode, used on erasing entries
    map<char, TrieNode *> child;
    TrieNode(TrieNode *parent = NULL, int height = 1) : parent(parent),
                                                        leaf(0),
                                                        height(height),
                                                        count(0), // change to -1 if leaf nodes are to have count 0 insead of 1
                                                        child()
    {
    }
};

/**
 * Complexity: O(|key| * log(k))
 */
TrieNode *trie_find(TrieNode *root, const string &str)
{
    TrieNode *pNode = root;
    for (string::const_iterator key = str.begin(); key != str.end(); key++)
    {
        if (pNode->child.find(*key) == pNode->child.end())
            return NULL;
        pNode = pNode->child[*key];
    }
    return (pNode->leaf) ? pNode : NULL; // returns only whole word
    // return pNode; // allows to search for a suffix
}

/**
 * Complexity: O(|key| * log(k))
 */
void trie_insert(TrieNode *root, const string &str)
{
    TrieNode *pNode = root;
    root->count += 1;
    for (string::const_iterator key = str.begin(); key != str.end(); key++)
    {
        if (pNode->child.find(*key) == pNode->child.end())
            pNode->child[*key] = new TrieNode(pNode, pNode->height + 1);
        pNode = pNode->child[*key];
        pNode->count += 1;
    }
    pNode->leaf += 1;
}

/**
 * Complexity: O(|key| * log(k))
 */
void trie_erase(TrieNode *root, const string &str)
{
    TrieNode *pNode = root;
    string::const_iterator key = str.begin();
    for (; key != str.end(); key++)
    {
        if (pNode->child.find(*key) == pNode->child.end())
            return;
        pNode = pNode->child[*key];
    }
    pNode->leaf -= 1;
    pNode->count -= 1;
    while (pNode->parent != NULL)
    {
        if (pNode->child.size() > 0 || pNode->leaf)
            break;
        pNode = pNode->parent, key--;
        pNode->child.erase(*key);
        pNode->count -= 1;
    }
}

char reverse_char_one_zero(char x)
{
    return (x == '1') ? '0' : '1';
}

string int_to_binary_string(int x)
{
    return bitset<32>(x).to_string();
}

int binary_string_to_int(string &str)
{
    return stoi(str, nullptr, 2);
}

int trie_maximum_xor(TrieNode *root, const string &str)
{
    TrieNode *pNode = root;
    string answer;

    for (string::const_iterator key = str.begin(); key != str.end(); key++)
    {
        if (pNode->child.count(reverse_char_one_zero(*key)) > 0)
        {
            answer.push_back('1');
            pNode = pNode->child[reverse_char_one_zero(*key)];
        }
        else
        {
            answer.push_back('0');
            pNode = pNode->child[*key];
        }
    }
    return binary_string_to_int(answer);
}

/*Driver function*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    TrieNode *root = new TrieNode();
    trie_insert(root, int_to_binary_string(0));

    int n;
    cin >> n;
    while (n--)
    {
        char operation;
        int value;
        cin >> operation >> value;
        if (operation == '+')
        {
            trie_insert(root, int_to_binary_string(value));
        }
        else if (operation == '-')
        {
            trie_erase(root, int_to_binary_string(value));
        }
        else
        {
            cout << trie_maximum_xor(root, int_to_binary_string(value)) << "\n";
        }
    }
}
