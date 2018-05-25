#include <bits/stdc++.h>

using namespace std;




int main()
{
    vector< tuple<int, int, int> > coords;
    vector< int > q;
    map<tuple<int, int>, int> mcoords;
    int N; cin >> N;
    while(N--)
    {
        int X, Y;
        cin >> X >> Y;
        coords.push_back(make_tuple(X, Y, 2));
    }
    for (int i = 0; i < coords.size(); i++)
    {
        mcoords.insert(make_pair(make_tuple(get<0>(coords[i]), get<1>(coords[i])), i));
    }
    // DFS
    int min_color = 0;
    for(int k = 0; k < coords.size(); k++)
    {
        int colors[2] = {0, 0};
        if (get<2>(coords[k]) == 2)
        {
            q.push_back(k);
            get<2>(coords[k]) = 1;
            colors[1] = 1;
        }
        while(!q.empty())
        {
            int current = q.back(); q.pop_back();
            int x = get<0>(coords[current]);
            int y = get<1>(coords[current]);
            int current_color = get<2>(coords[current]);
            for (int i = -5; i <= 5; i++)
            {
                for (int j = -5; j <= 5; j++)
                {
                    auto it = mcoords.find(make_tuple(x + i, y + j));
                    if (it != mcoords.end() and (get<2>(coords[it->second]) == 2) and (i*i + j*j) <= 25)
                    {
                        get<2>(coords[it->second]) = current_color^1;
                        colors[current_color^1] += 1;
                        q.push_back(it -> second);
                    }
                }
            }
        }
        min_color = min_color + min(colors[0], colors[1]);
    }
    cout << min_color << endl;
}