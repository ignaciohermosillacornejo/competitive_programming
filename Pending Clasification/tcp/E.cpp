#include <bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, n) for(int i = a; i < n; i++)
#define eb emplace_back

#define debugv(v) cerr<<#v<<':'; for(auto e: v) cerr<<' '<<e;cerr<<endl

vvvd memo(2);
vd acum;
int m;

double dp(int ext, int i, int j){
    if(memo[ext][i][j] >= 0) return memo[ext][i][j];
    if(i > m or j < m)
        return memo[ext][i][j] = 1e9;
    if (i == j)
        return memo[ext][i][j] = 0;
    if(ext == 1){
        double a = dp(1,i,j-1) + 1 - acum[j-1] + acum[i];
        double b = dp(0,i,j-1) + (j - i)*(1 - acum[j-1] + acum[i]);
        return memo[ext][i][j] = min(a,b);
    }
    else{
        double a = dp(0,i+1,j) + 1 - acum[j] + acum[i+1];
        double b = dp(1,i+1,j) + (j - i)*(1 - acum[j] + acum[i+1]);
        return memo[ext][i][j] = min(a,b);
    }
}



int main(){
    cout.setf(ios::fixed); cout.precision(6);
    cin>>m;
    memo[0].assign(2*m + 1,vd(2*m+1,-1));
    memo[1].assign(2*m + 1,vd(2*m+1,-1));
    acum.assign(2*m+1,0);

    rep(i,2*m){
        cin>> acum[i+1];
        acum[i+1] += acum[i];
    }
    double a = dp(0,0,2*m);
    double b = dp(1,0,2*m);
    cout<< min(a,b)<<'\n';

}