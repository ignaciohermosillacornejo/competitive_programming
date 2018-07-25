#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> par;
typedef vector<par> vp;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> graph;
typedef vector<vector<par>> wgraph;
typedef vector<par> vpar;



int main()
{
    int ts, tf, dt; cin >> ts >> tf >> dt;
    int n; cin >> n;
    vi arr(n);
    priority_queue<par> q;
    int last = 0;
    rep(i, n)
    {
        int x; cin >> x;
        if(!q.empty()){
            if(q.top().first == x){
                ll s = q.top().second;
                q.emplace(make_pair(x,s+dt));
            }
            else q.emplace(make_pair(x,dt));
        }
        else
            q.emplace(make_pair(x,dt));
        arr[i] = x;
    }
    if (n == 0 or arr[0] > ts)
    {
        cout << ts << "\n";
        return 0;
    }
    ll unoccupied = arr[0] + dt;
    ll i = 1;
    ll s_time;
    ll m = 1e12 + 1;
    //queue<par> q; 
    // 0 llego alguien
    // 1 se fue alguien
    // 2
    ll last_time = 0;
    ll count = q.top().second;
    ll best = q.top().first + ts;q.pop();
    while(!q.empty())
    {
        par s = q.top();q.pop();
        ll now = s.first;
        ll people = s.second;
        ll dif = min()
        best = min(best,count - (now - last_time - 1));
        count += people;
        last_time = now;




        //q.push({arr[i], unoccupied + dt});
        //unoccupied += dt;



        //i++;
    }
    cout<<max(best,0ll)<<endl;



}