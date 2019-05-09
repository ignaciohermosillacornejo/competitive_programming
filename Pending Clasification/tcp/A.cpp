#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;


#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, n) for(int i = a; i < n; i++)
#define eb emplace_back

#define debugv(v) cerr<<#v<<':'; for(auto e: v) cerr<<' '<<e;cerr<<endl

struct Pos
{
    int row;
    int col;
    int o;
};


struct Move
{
    Pos last_pos;
    int move;
};

int height, width;
//vi moves;
Pos goal, start;
vvc grid;
vvvi dp;
vector< vector< vector < Move > > > moves;
char print_moves[4] = {'U', 'R', 'D', 'L'};

/* Orientation
 * 0: standing
 * 1: vertical
 * 2: horizontal
 */

/* Moves
 * 0: U
 * 1: R
 * 2: D
 * 3: L
 */

Pos performMove(Pos current, int move)
{
    if (!current.o)
    {
        if (move == 0)
        {
            current.row -= 2;
            current.o = 1; 
        }
        else if (move == 1)
        {
            current.col += 1;
            current.o = 2;
        }
        else if (move == 2)
        {
            current.row += 1;
            current.o = 1;
        }
        else if (move == 3)
        {
            current.col -= 2;
            current.o = 2;
        }
    }
    else if (current.o == 1) // vertical
    {
        if (move == 0)
        {
            current.row -= 1;
            current.o = 0; 
        }
        else if (move == 1)
        {
            current.col += 1;
        }
        else if (move == 2) // down
        {
            current.row += 2;
            current.o = 0;
        }
        else if (move == 3)
        {
            current.col -= 1;
        }
    }
    else if (current.o == 2) // horizontal
    {
        if (move == 0) // U
        {
            current.row -= 1;
        }
        else if (move == 1) // R
        {
            current.col += 2;
            current.o = 0;
        }
        else if (move == 2) // D
        {
            current.row += 1;
        }
        else if (move == 3) // L
        {
            current.col -= 1;
            current.o = 0;
        }
    }
    return current;
}

void printPos(Pos &pos)
{
    cout << "[" << pos.row << "][" << pos.col << "]" << ": " << pos.o << "\n";
}

// returns true of false if we can make te move
bool isSafe(Pos current, int move, int n_moves)
{
    Pos new_pos = performMove(current, move);
    //printPos(new_pos);

    // check if new pos is valid
    if (new_pos.row < 0) // upper boundary
    {
        return false;
    }
    else if (new_pos.col < 0) // left boundary
        return false;
    // bottom boundary
    else if ((new_pos.row >= height - 1 && new_pos.o == 1) or new_pos.row >= height) 
        return false;
    // right boundary
    else if ((new_pos.col >= width - 1 && new_pos.o == 2) or new_pos.col >= width)
        return false; 


    if (grid[new_pos.row][new_pos.col] == '#')
        return false;
    else if (new_pos.o == 1 and grid[new_pos.row + 1][new_pos.col] == '#')
        return false;
    else if (new_pos.o == 2 and grid[new_pos.row][new_pos.col + 1] == '#')
        return false;

    // we check the number of moves
    if (n_moves >= dp[new_pos.row][new_pos.col][new_pos.o])
        return false;

    return true;
}

void printPath(Pos current)
{
    if (current.row == start.row and current.col == start.col and current.o == start.o)
        return;
    printPath(moves[current.row][current.col][current.o].last_pos);
    cout << print_moves[moves[current.row][current.col][current.o].move];
}

void solver(Pos current, int n_moves)
{
    // return if reached exit
    if (current.row == goal.row and current.col == goal.col and current.o == goal.o)
        return;

    // for posible moves
    rep(move, 4)
    {
        if (isSafe(current, move, n_moves))// if move is safe
        {
            // perform move
            Move record_move;
            record_move.last_pos = current;
            record_move.move = move; 

            current = performMove(current, move);
            // we save the last position and move that got us there
            dp[current.row][current.col][current.o] = n_moves + 1;
            moves[current.row][current.col][current.o] = record_move;

            // recursive solver
            solver(current, n_moves + 1);

            // backtrack
            current = performMove(current, (move + 2) % 4);
        }
    }
}

int main()
{

    cin >> height >> width;
    grid.assign(height, vc(width)); 
    dp.assign(height, vvi(width, vi(3)));
    moves.assign(height, vector< vector<Move>>(width, vector<Move>(3)));
    rep(row, height)
    {
        rep(col, width)
        {
            char value; cin >> value;
            if (value == 'E')
            {
                goal.row = row;
                goal.col = col;
                goal.o = 0;
                value = '.';
            }
            else if (value == 'C')
            {
                start.row = row;
                start.col = col;
                start.o = 0;
                value = '.';
            }
            grid[row][col] = value;
            
            dp[row][col][0] = INT_MAX;
            dp[row][col][1] = INT_MAX;
            dp[row][col][2] = INT_MAX;
        }
    }

    solver(start, 0);
    if (dp[goal.row][goal.col][0] != INT_MAX)
    {
        cout << dp[goal.row][goal.col][0] << "\n";
        printPath(goal);
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    
}