/*
Problem: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2483
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

struct Trie
{
    bool isEndOfWord; // isEndOfWord is true if the node represents end of a word
    int height;       // height of our node
    int children;     // number of children that are on current path
    /* nodes store a map to child node */
    unordered_map<char, Trie *> map;
};

/*function to make a new trie*/
Trie *getNewTrieNode()
{
    Trie *node = new Trie;
    node->isEndOfWord = false;
    node->height = 0;
    node->children = 0;
    return node;
}

/*function to insert in trie*/
void insert(Trie *&root, const string &str)
{
    if (root == nullptr)
        root = getNewTrieNode();

    Trie *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        char x = str[i];

        /* make a new node if there is no path */
        if (temp->map.find(x) == temp->map.end())
        {
            temp->map[x] = getNewTrieNode();
            temp->map[x]->height = temp->height + 1;
        }

        temp = temp->map[x];
        temp->children += 1;
    }

    temp->isEndOfWord = true;
}

int count(Trie *root)
{
    /*return 0 if Trie is empty*/
    if (root == nullptr)
        return 0;

    int ans = root->height * root->children;

    for (auto i : root->map)
        ans = max(ans, count(i.second));

    return ans;
}

/*Driver function*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        Trie *root = nullptr;

        while (N--)
        {
            string word;
            cin >> word;
            insert(root, word);
        }
        cout << count(root) << "\n";
    }
}
