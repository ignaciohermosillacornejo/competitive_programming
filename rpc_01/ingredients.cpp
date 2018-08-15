#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> graph;
typedef vector<ii> vii;
typedef vector<vii> wgraph;

#define rep(i,n) for (size_t i = 0; i < (size_t)n; ++i)
#define repx(i,a,b) for (size_t i = a; i < (size_t)b; ++i)
#define invrep(i,a,b) for (int i = b; i >= (int)a; --i)

#define pb push_back
#define eb emplace_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gdc __gcd


struct edge
{
	ll c;
	ll p;
	string to;
	edge(ll c, ll p, string to): c(c), p(p), to(to){}
};


struct dish
{
	ll acum_c;
	ll acum_p;
	bool updated;
	vector<edge> parents;
};

ii update(unordered_map<string, dish> &hash, string root)
{
	if (root == "*") // top of the tree reached
		return make_pair(0, 0);

	for (auto &p : hash[root].parents)
	{
		string parent = p.to;

		if(!hash[parent].updated) // we iteratively call if the parent hasn't been updated
			update(hash, parent);

		if (hash[root].acum_c > hash[parent].acum_c + p.c or (hash[root].acum_c == hash[parent].acum_c + p.c and hash[root].acum_p < hash[parent].acum_p + p.p))
		{
			hash[root].acum_c = hash[parent].acum_c + p.c;
			hash[root].acum_p = hash[parent].acum_p + p.p;
		}
	}
	hash[root].updated = true;
	return make_pair(hash[root].acum_c, hash[root].acum_p);
}

void knapSack(int W, vi wt, vi val, int n)
{
	ll K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0) // base case (no items and no weight left)
				K[i][w] = 0;
			else if (wt[i - 1] <= w) // case when we can add the last item, then we keep the max between adding it or leaving it out
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else // case when we can't add the last items
				K[i][w] = K[i - 1][w];
		}
	}
	cout << K[n][W] << '\n';
	ll w = W;
	ll res = K[n][w];
	ll total_cost = 0;

	for (int i = n; i > 0 && res > 0; i--)
	{

		// either the result comes from the top
		// (K[i-1][w]) or from (val[i-1] + K[i-1]
		// [w-wt[i-1]]) as in Knapsack table. If
		// it comes from the latter one/ it means
		// the item is included.
		if (res == K[i - 1][w])
			continue;
		else
		{
			// This item is included.
			//cout << wt[i - 1] << '\n';
			total_cost += wt[i - 1];

			// Since this weight is included its
			// value is deducted
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
	cout << total_cost << '\n';
}

int main()
{
	int b; cin >> b;
	int n; cin >> n;

	unordered_map<string, dish> hash; // cost, prestiege
	hash["*"] = {0, 0, true, vector<edge>()};

	rep(i, n)
	{
		string id; string parent; string added; int c; int p;
		cin >> id >> parent >> added >> c >> p;

		auto it_id = hash.find(id);
		auto it_p = hash.find(parent);

		if (it_id != hash.end())		
		{	
			if (it_p != hash.end()) // existe y tiene padre
			{
				hash[id].parents.eb(c, p, it_p->first);
			}
		}
		else
		{
			if (it_p != hash.end()) // no existe y tiene padre
			{
				hash[id] = {(ll)1e11, 0, false, vector<edge>()};
				hash[id].parents.eb(c, p, it_p->first);
			}
			else // no existe y no tiene padre
			{
				hash[id] = {(ll)1e11, 0, false, vector<edge>()};
				hash[id].parents.eb(c, p, "*");
			}
		}
	}

	vi wheights;
	vi values;

	for (auto & par: hash)
	{
		update(hash, par.first);
		wheights.eb(par.second.acum_c);
		values.eb(par.second.acum_p);
	}

	knapSack(b, wheights, values, n);

	string t = "pizza_spicy";
	cout << hash[t].acum_c << '\n';
	cout << hash[t].acum_p << '\n';
}