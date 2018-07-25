#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;

class Trie
{
  public:
    vvi nodes;
    vi height;
    vi isleaf;
    int next, TOTAL_NEIGHBOURS;

    Trie(int neighbours)
    {
        next = 1;
        TOTAL_NEIGHBOURS = neighbours;
        nodes = vvi(1, vi(TOTAL_NEIGHBOURS, -1));
        height = vi(1, 0);
        isleaf = vi(1,0);
    }

    void build(string s)
    {
        int i = 0, v = 0;
        while (i < s.size())
        {
            if (nodes[v][s[i]-'0'] == -1)
            {
                nodes.push_back(vi(TOTAL_NEIGHBOURS, -1));
                v = nodes[v][s[i]-'0'] = next;
                height.eb(i);
                isleaf.eb(0);
                if(i==s.size()-1) isleaf[next] = 1;
                i++, next++;
            }
            else
            {
                v = nodes[v][s[i]-'0'];
                if(i==s.size()-1) isleaf[v] = 1;
                i++;
            }
        }
    }

    string search_best(string s){
        int i = 0;
        int v = 0;
        string r = "";
        while(i < s.size()){
            if(nodes[v][s[i]-'0'] != -1){
                r+=s[i];
                v = nodes[v][s[i]-'0'];
                i++;
            }
            else if(nodes[v]['1' - s[i]] != -1){
                r += '1' - s[i] + '0';
                v = nodes[v]['1'-s[i]];
                i++;
            }
            else break;
        }
        return r;
    }
};

string itob(int i){
    string res = "000000000000000000000000000000";
    int count = 29;
    while(i){
        if(i%2==1)
            res[count] = '1';
        i>>=1;
        count--;
    }
    return res;
}

void traverse(wgraph& g, int i, int parent, int val, Trie& trie, vi& weights){
    for(auto a: g[i]){
        if(a.second == parent) continue;
        trie.build(itob(val ^ a.first));
        weights[a.second] = val ^ a.first;
        //cout<<(val ^ a.first)<<endl;
        traverse(g,a.second,i,val^a.first,trie,weights);
    }
}


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin>>n){
        wgraph gra(n);
        rep(i,n-1){
            int a,b,c;
            cin>>a>>b>>c;
            a--;b--;
            gra[a].eb(c,b);
            gra[b].eb(c,a);
        }
        //rep(i,n) {rep(j,gra[i].size()) cout<<gra[i][j].second<<" ";cout<<endl;}
        vi weights(n,0);
        Trie trie(2);
        trie.build("000000000000000000000000000000");
            traverse(gra, 0, -1, 0, trie, weights);
        rep(i,n){
            int p = weights[i] ^ 0b111111111111111111111111111111;
            string s = trie.search_best(itob(p));
            cout <<(stoi(s,nullptr,2)^weights[i])<<endl;
        }
    }
    return 0;
}