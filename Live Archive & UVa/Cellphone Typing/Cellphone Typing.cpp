/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=572&page=show_problem&problem=4144 
Tags: Strings, Trie
Status: WA
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> wgraph;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x)  //cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl
#endif

struct Trie
{
    bool isEndOfWord; // isEndOfWord is true if the node represents end of a word
    int height;       // height of our node
    int freq;         // number of times we passed through node (leaf nodes are 1)
    /* nodes store a map to child node */
    unordered_map<char, Trie *> map;
};

/*function to make a new trie*/
Trie *getNewTrieNode()
{
    Trie *node = new Trie;
    node->isEndOfWord = false;
    node->height = 0;
    node->freq = 0;
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

        temp->freq += 1;
        temp = temp->map[x];
    }

    temp->isEndOfWord = true;
    temp->freq += 1;
}

int count(Trie *root)
{
    /*return 0 if Trie is empty*/
    int c = 0;

    if (root->isEndOfWord)
        c += 1;

    if (root->freq == 1)
        return c;

    if (root->map.size() > 1)
        c += root->freq;

    for (auto i : root->map)
        c += count(i.second);

    return c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(2);
    int T;
    while (cin >> T)
    {
        Trie *root = nullptr;
        rep(i, T)
        {
            string s;
            cin >> s;
            insert(root, s);
        }
        cout << root->freq << "\n";
        //cout << ((double)count(root))/T << "\n";
        return 0;
    }
}