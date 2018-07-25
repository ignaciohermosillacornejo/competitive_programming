/* https://www.urionlinejudge.com.br/judge/en/runs */
#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

/* structs for the problem */
const int max_n = 1e5 + 1;
int n, m;
vll accumulated;
struct edge;
priority_queue<pair<int, ll>, vector< pair<int, ll> >, greater< pair<int, int> > > q;
vector<vector <edge> > graph;


struct edge
{
    int d;
    int w;
    edge(int d, int w): d(d), w(w) {}
};


void print_graph()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (edge d : graph[i])
        {
            cout << d.d << " ";
        }
        cout << endl;
    }
}

void add_edges(int l, int upper, int w)
{
    for (int i = l + 1; i <= upper; i++)
    {
        graph[l].emplace_back(edge(i, w));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> m)
    {
        accumulated.assign(n, 0); // initialize our acumulated vector
        accumulated.emplace_back(LLONG_MAX); // all paths that end the game end at level n
        graph.clear();
        q.empty();
        graph.resize(n + 1); // initialize the graph the graph with 1 extra level (that we use as our end node)
        vll weight(n + 1, LLONG_MAX); // used to store the wheights in our dijkstra
        for (int i = 0; i < n; i++)
        {
            cin >> accumulated[i];
            if (i)
                accumulated[i] += accumulated[i - 1];
        }

        ll x;
        for (int i = 0; i < m; i++)
        {
            int l, s, c;
            cin >> l >> s >> c;
            l--;

            // binary search for the highest level that can be reached from that particular store
            if (l) x = accumulated[l - 1]; // for edge case when i == 0
            else x = 0;
            int upper = upper_bound(accumulated.begin(), accumulated.end(), s + x) - accumulated.begin();
            add_edges(l, upper, c);
        }

        print_graph();

        // start our dijkstra
        q.push(make_pair(0, 0));
        weight[0] = 0;

        while(!q.empty())
        {
            int v = q.top().second; q.pop();

            for (auto i : graph[v])
            {
                if (weight[v] + i.w < weight[i.d])
                {
                    weight[i.d] = weight[v] + i.w;
                    if (i.d == n)
                        break;
                    q.push(make_pair(weight[i.d], i.d));
                }
            }
        }
        if (weight[n] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << weight[n] << endl;
        }
    }
}
