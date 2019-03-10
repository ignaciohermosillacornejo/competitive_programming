#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, n) for(int i = a; i < n; i++)
#define eb emplace_back

#define debugv(v) cerr<<#v<<':'; for(auto e: v) cerr<<' '<<e;cerr<<endl

int main(){
    int n,m;
    cin>>n>>m;
    vi lol(m,0);
    rep(i,n){
        int u;
        cin>>u;
        u--;
        lol[u]++;
    }
    int k = 0;
    int repetidos = 0;
    rep(i,m){
        if(lol[i] > 0){
            k++;
            if(lol[i] > 1){
                repetidos++;
            }
        }
    }
    if(repetidos > 1 and k < m)
        cout<< m<<endl;
    else if(repetidos == 0 and k < m){
        if(k==2)
            cout<<m-2<<endl;
        else if(k==3 and m ==4)
            cout<< 3<<endl;
        else
            cout<< m <<endl;
    }
    else if(repetidos == 1){
        if(k >= 3)
            cout<<m<<endl;
        else if(k==2)
            cout <<m-1<<endl;
        else
            cout<< 1<<endl;
    }
    else
        cout<< 0 <<endl;
}