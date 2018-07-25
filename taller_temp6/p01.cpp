#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr<<#x<<": "<<x<<endl


typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int maxn = 40000;



/* find the furthest away node from the */
int bfs(vvi &graph, int s)
{
    int distance[maxn];
    memset(distance, -1, maxn);
    int most_distant_node = s;

    queue<int> q;
    q.push(s);

    distance[s] = 0;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int neighbour : graph[current])
        {
            if (distance[neighbour] == -1)
            {
                q.push(neighbour);
                distance[neighbour] = distance[current] + 1;
                if (distance[neighbour] > distance[most_distant_node]){
                    most_distant_node = neighbour;
                }
            }
        }
    }
    return most_distant_node;
}

/* find the distance from one of the extreme edges to every other node and 
update the node if it is longer than from the other edge */
void bfs(vvi &graph, vi  &maxdist, int s){
    int distance[maxn];
    memset(distance, -1, maxn);

    queue<int> q;
    q.push(s);

    distance[s] = 0;
    while(!q.empty()){
        int current = q.front(); q.pop();

        for (int neighbour: graph[current]){
            if (distance[neighbour] == -1){
                q.push(neighbour);
                distance[neighbour] = distance[current] + 1;
                maxdist[neighbour] = max(maxdist[neighbour], distance[neighbour]);
            }
        }
    }
}

int get_diameter(vvi &graph, vi &maxdist)
{
    int e1 = bfs(graph, 0);
    int e2 = bfs(graph, e1);
    
    bfs(graph, maxdist, e1);
    bfs(graph, maxdist, e2);

    assert(maxdist[e1] == maxdist[e2]);
    return maxdist[e1];
}

int main()
{
    int n, m;
    ios::sync_with_stdio(0);

    cout << fixed << setprecision(3);
    cin.tie(0);

    while (cin >> n >> m){
        n--;m--;
        vvi nlogonia; nlogonia.assign(n + 1, vi());
        vvi quadronia; quadronia.assign(m + 1, vi());
        int a, b;

        vi maxdist_n; maxdist_n.assign(n + 1, 0);
        vi maxdist_q; maxdist_q.assign(m + 1, 0);

        for (int i = 0; i < n; i++){
            cin >> a >> b; a--; b--;
            nlogonia[a].push_back(b);
            nlogonia[b].push_back(a);
        }
        for (int i = 0; i < m; i++){
            cin >> a >> b; a--; b--;
            quadronia[a].push_back(b);
            quadronia[b].push_back(a);
        }
        int diameter_n = get_diameter(nlogonia, maxdist_n);
        int diameter_q = get_diameter(quadronia, maxdist_q);
        int max_diameter = max(diameter_n, diameter_q);

        sort(maxdist_n.begin(), maxdist_n.end());
        sort(maxdist_q.begin(), maxdist_q.end());

        vll acumulated; acumulated.assign(m + 1, 0);

        for (int i = 0; i < m + 1; i++){
            acumulated[i] = maxdist_q[i];
            if (i) {
                acumulated[i] += acumulated[i-1];
            }
        }

        double total = 0;

        for (int i = 0; i < n + 1; i++)
        {
            debugx(i);
            int target = max_diameter - maxdist_n[i] - 1;
            debugx(target);
            int index = upper_bound(maxdist_q.begin(), maxdist_q.end(), target) - maxdist_q.begin();
            total += index * max_diameter;
            debugx(total);
            total += acumulated[m] - acumulated[index - 1];
            debugx(total);
            total += (maxdist_n[i] + 1) * ((m + 1) - index);
            debugx(total);
        }
        cout << (double)total/(double)((m + 1) * (n + 1)) << endl;
    }


}

