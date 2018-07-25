#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long intt;

intt mod = 1e8+7;


int main(){
    int t;
    cin >> t;
    rep(cas,t){
        int n;
        cin>>n;
        intt prod = 1;
        rep(i,n-1){
            prod *= 2;
            prod%=mod;
        }
        intt sum = 0;
        rep(i,n){
            intt here;
            cin>> here;
            here %= mod;
            intt S = here * prod;
            S %= mod;
            sum+=S;
            sum%=mod;
        }
        cout<<"Case "<<cas+1<<": "<<sum<<endl;
    }
}