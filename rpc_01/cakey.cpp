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


int main(){
	int n, m;
	cin >> n >> m;
	vi in(n);
	vi out(m);
	rep(i, n)
	{
		cin >> in[i]; 
	}
	rep(i, m)
	{
		cin >> out[i];
	}

	map<int, int> hash;

	rep(i, n)
	{
		rep(j, m)
		{
			int dif = out[j] - in[i];
			if (dif >= 0)
			{
				auto it = hash.find(dif);
				if (it != hash.end())
				{
					hash[dif] += 1;
				}
				else
				{
					hash[dif] = 1;
				}
			}
		}
	}

	int max_c = 0;
	int temp = 0;

	for (auto a: hash)
	{
		if(max_c < a.second){
			max_c = a.second;
			temp = a.first;
		}
	}

	cout << temp << "\n";
}