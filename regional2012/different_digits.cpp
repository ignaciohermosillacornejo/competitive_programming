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

int main(){
    int n,m;
    while(cin>>n>>m){
        int counter = 0;
        repx(i,n,m+1){
            int a = i%10;
            int b = (i/10)%10;
            int c = (i/100)%10;
            int d = i/1000;
            if(d==0){
                d=10;
                if(c==0){
                    c=11;
                    if(b==0){
                        d=12;
                    }
                }
            }
            if(a==b or a==c or a==d or b==c or b==d or c==d);
            else counter++;
        }
        cout<<counter<<endl;
    }
}