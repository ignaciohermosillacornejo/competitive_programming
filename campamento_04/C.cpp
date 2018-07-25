#include <bits/stdc++.h>
using namespace std;
#define debugx(x) //cerr << #x << ": " << x << endl
#define debugp(x) //cerr << #x << ": (" << x.first << "," << x.second << ")" << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef pair<double, double> pard;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> graph;
typedef vector<vector<par>> wgraph;

class UnionFind
{
  private:
    vi p, rank;
    int numSets;

  public:
    UnionFind(int N)
    {
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    void reset(){
        int N = p.size();
        rep(i,N) p[i] = i;
        rank.assign(N, 0);
        numSets = N;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
};

double dist(par a, par b){
    return  (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) ;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, h;
    while(cin>>n>>w>>h){
        //cerr<<"Next\n";
        if(n == -1)
            break;
        vector< par> din;
        rep(i,n){
            int x,y;
            cin>>x>>y;
            din.eb(x,y);
        }
        double l = 0, r = max(w,h);
        UnionFind g(n+2);
        rep(_, 90){
            double m = (l+r)*0.5;
            g.reset();
            rep(i,n){
                int flag = 0;
                if (din[i].first < m or h - din[i].second < m){
                    flag++;
                    g.unionSet(i, n);
                }

                if (w - din[i].first < m or din[i].second < m){
                    flag++;
                    g.unionSet(i, n + 1);
                }
                if(flag == 2)
                    goto range;
            }
            rep(i,n){
                for(int j = i; j < n; j++)
                    if(dist(din[i], din[j]) <= 4*m*m){
                        g.unionSet(i,j);
                        if (g.isSameSet(n, n + 1))
                            goto range;
                    }
            }
            range:
            if(g.isSameSet(n, n+1))
                r = m;
            else
                l = m;
        }
        cout<<(l+r)*0.5<<"\n";
    }


    return 0;
}