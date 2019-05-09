/*
Problem: https://codeforces.com/problemset/problem/3/A
Tags: Graph, Greedy
Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repx(i, x, n) for (int i = x; i < n; ++i)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
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
    char x_char;
    int y;
    cin >> x_char >> y;
    int x = (int)x_char;

    int x_2, y_2;
    cin >> x_char >> y_2;
    x_2 = (int)x_char;

    int x_1 = x;
    int y_1 = y;
    int count = 0;

    while (x != x_2 or y != y_2)
    {
        count++;
        if (x == x_2 and y < y_2) // move up
        {
            y++;
        }
        else if (x == x_2 and y > y_2) // move down
        {
            y--;
        }
        else if (x < x_2 and y == y_2) // move right
        {
            x++;
        }
        else if (x > x_2 and y == y_2) // move left
        {
            x--;
        }
        else if (x < x_2 and y < y_2) // move up and right
        {
            y++;
            x++;
        }
        else if (x > x_2 and y < y_2) // move up left
        {
            y++;
            x--;
        }
        else if (x < x_2 and y > y_2) // move down right
        {
            y--;
            x++;
        }
        else // move down left
        {
            y--;
            x--;
        }
    }

    x = x_1;
    y = y_1;
    cout << count << "\n";
    while (x != x_2 or y != y_2)
    {
        if (x == x_2 and y < y_2) // move up
        {
            y++;
            cout << "U\n";
        }
        else if (x == x_2 and y > y_2) // move down
        {
            y--;
            cout << "D\n";
        }
        else if (x < x_2 and y == y_2) // move right
        {
            x++;
            cout << "R\n";
        }
        else if (x > x_2 and y == y_2) // move left
        {
            x--;
            cout << "L\n";
        }
        else if (x < x_2 and y < y_2) // move up and right
        {
            y++;
            x++;
            cout << "RU\n";
        }
        else if (x > x_2 and y < y_2) // move up left
        {
            y++;
            x--;
            cout << "LU\n";
        }
        else if (x < x_2 and y > y_2) // move down right
        {
            y--;
            x++;
            cout << "RD\n";
        }
        else // move down left
        {
            y--;
            x--;
            cout << "LD\n";
        }
    }
}