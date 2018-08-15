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
#define invrep(i,a,b) for (int i = b; i >= (int)a; --i)

#define pb push_back
#define eb emplace_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gdc __gcd

typedef double compt;

struct point
{
	compt x,y;
	point(): x(0),y(0){}
	point(compt x, compt y): x(x), y(x) {}
	bool operator<(point const &o) const {
		return make_pair(x,y) < make_pair(o.x, o.y);
	} 
};
compt cross(point o, point a, point b){
	return (a.x - o.x)*(b.y - o.y)-(a.y - o.y)*(b.x - o.x);
}

compt dist(point a,point b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

void convex_hull(vector<point> &p, vector< point> &ch){
	sort(p.begin(), p.end());
	vector<point> L, U;
	int n = p.size();
	#define tmp(x) {while(x.size() >= 2 and cross(x[x.size()-2],x.back(),p[i])<=0){x.pop_back();}x.pb(p[i]);}
	rep(i,n) tmp(L) invrep(i,0,n-1) tmp(U)
	#undef tmp
	rep(i,L.size()-1) ch.pb(L[i]);
	rep(i,U.size()-1) ch.pb(U[i]);
}


int main(int argc, char const *argv[])
{
	cout.setf(ios::fixed); cout.precision(17);
	int n,r;
	cin>>n>>r;
	vector<point> candles(n);
	vector<point> hull;
	rep(i,n){
		cin>>candles[i].x>>candles[i].y;
	}
	convex_hull(candles,hull);
	hull.eb(hull[0]);
	hull.eb(hull[1]);
	double mindist = r;
	mindist *= mindist;
	int p1 = 0;
	int p2 = 0;
	while(p1 < n){
		while(dist(hull[p1],hull[p2+1]) >= dist(hull[p1],hull[p2])){
			p2%=n;
			p2++;
		}
		if(p2%n == (p1+1)%n or p2 == p1) {p1++;continue;}
		cout<<p1<<" "<<p2<<endl;
		double c = sqrt(dist(hull[p2],hull[p2-1]));
		double a = sqrt(dist(hull[p1],hull[p2-1]));
		double b = sqrt(dist(hull[p1],hull[p2]));

		double s = a + b + c;
		s/=2;
		double As = s*(s-a)*(s-b)*(s-c);
		cout<<a<<" "<<b<<" "<<c<<endl;
		mindist = min(mindist,4*As/(c*c));

		p1++;
	}
	cout<<sqrt(mindist)<<endl;
	return 0;
}