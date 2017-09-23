//http://codeforces.com/problemset/problem/839/C
// implementacion sacada de http://www.sanfoundry.com/cpp-program-implement-adjacency-list/
#include <bits/stdc++.h>

std::vector< std::vector<int> > graph;


int main()
{
    int n = 5;
    graph.reserve(n);
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].push_back(0);
    }

    for (int i = 0; i < graph.size(); i++)
    {
        std::cout << graph[i][0];
    }
    return 0;
}