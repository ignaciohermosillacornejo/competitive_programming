#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef vector<ii> vii;
typedef vector<vii> wgraph;

#define rep(i,n) for (size_t i = 0; i < (size_t)n; ++i)
#define repx(i,a,b) for (size_t i = a; i < (size_t)b; ++i)
#define invrep(i,a,b) for (size_t i = b; i >= (size_t)a; --i)

#define pb push_back
#define eb emplace_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gdc __gcd

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);cin.tie(0);
	ll w,n;
	cin>>w>>n;
	ll area = 0;
	rep(i,n){
		ll ws,l;
		cin>>ws>>l;
		area += ws*l;
	}
	cout<<area/w<<'\n';
	return 0;
}