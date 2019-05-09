/*
Problem: https://open.kattis.com/problems/cool1
Tags: simulation, implementation, shortest repeating cycle (KMP)
Status: WA
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vii> wgraph;

typedef vector<char> vc;
typedef vector<vc> vvc;

#ifndef declaraciones_h
#define declaraciones_h

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

#define debugx(x)  //cerr<<#x<<": "<<x<<endl
#define debugv(v)  //cerr<<#v<<":";rep(i,(int)v.size())cerr<<" "<<v[i];cerr<<endl
#define debugm(m)  //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" "<<m[i][j];cerr<<endl;}
#define debugmp(m) //cerr<<#m<<endl;rep(i,(int)m.size()){cerr<<i<<":";rep(j,(int)m[i].size())cerr<<" {"<<m[i][j].first<<","<<m[i][j].second<<"}";cerr<<endl;}
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

#endif

// structs
struct state
{
    int instruction;
    int row;
    int col;
};

// global vars
string instructions;
vector<state> sequence;
vvc grid;
vvvi visited;

state create_state(int instruction, int row, int col)
{
    state new_state;
    new_state.instruction = instruction;
    new_state.row = row;
    new_state.col = col;
    return new_state;
}

state move_robot(state current)
{
    char move = instructions[current.instruction];
    if (move == '^' && grid[current.row - 1][current.col] != '#')
        current.row -= 1;
    else if (move == '>' && grid[current.row][current.col + 1] != '#')
        current.col += 1;
    else if (move == 'v' && grid[current.row + 1][current.col] != '#')
        current.row += 1;
    else if (move == '<' && grid[current.row][current.col - 1] != '#')
        current.col -= 1;
    current.instruction = (current.instruction + 1) % instructions.size();
    return current;
}

bool compare_states(state &a, state &b)
{
    return a.col == b.col and a.row == b.row and a.instruction == b.instruction;
}

void print_length_trail(state &current, int i)
{
    int grid_moves = sequence.size() - i - 1;
    if (sequence.back().row == current.row and sequence.back().col == current.col)
        grid_moves--;
    cout << grid_moves << "\n";
}

bool search_state(state &current, int position)
{
    if (visited[current.row][current.col][current.instruction] == -1)
    {
        visited[current.row][current.col][current.instruction] = position;
        return false;
    }
    return true;
}

void print_state(state &a)
{
    cout << "i: " << a.instruction << " [" << a.row << "][" << a.col << "] ";
}

void print_sequence()
{
    rep(i, sequence.size())
        print_state(sequence[i]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
    {
        state current;
        instructions.clear();
        sequence.clear();
        cin >> instructions;
        grid.assign(200, vc(200, '#'));
        visited.assign(200, vvi(200, vi(200, -1)));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                char c;
                cin >> c;
                if (c == 'R')
                {
                    current.instruction = 0;
                    current.row = row;
                    current.col = col;
                    c == '.';
                }
                grid[row][col] = c;
            }
        }
        sequence.eb(current);
        current = move_robot(current);
        int position = 0;
        while (true)
        {
            // current is the same as the last on the sequence -> we are stuck
            if (compare_states(sequence.back(), current)) // O(1)
            {
                cout << "1\n";
                break;
            }
            // current one is on the sequence but not last -> we have a loop, we print its length
            else if (sequence.size() != 1 and search_state(current, position)) // O(1)
            {
                print_length_trail(current, visited[current.row][current.col][current.instruction]);
                break;
            }
            // we add the new state if the position on grid is different from the last one
            // O(1)
            else if (sequence.back().col != current.col or sequence.back().row != current.row)
            {
                sequence.eb(current);
                position += 1;
            }
            // we advance the state
            current = move_robot(current);
        }
    }
    return 0;
}