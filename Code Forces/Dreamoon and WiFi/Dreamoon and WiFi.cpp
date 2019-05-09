/*
Problem: https://codeforces.com/problemset/problem/476/B
Tags: DP, Strings, Brute Force, Combinatorics
Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> posible_pos;
string recieved;
string sent;
int final_pos = 0;
float correct_out = 0;
float wrong_out = 0;

void get_posible_pos(int pos, string commands_left)
{
    if (commands_left.empty())
    {
        if (pos == final_pos)
        {
            correct_out += 1;
        }
        else
        {
            wrong_out += 1;
        }
    }
    else
    {
        if (commands_left.back() == '+')
        {
            commands_left.pop_back();
            get_posible_pos(pos + 1, commands_left);
        }
        else if (commands_left.back() == '-')
        {
            commands_left.pop_back();
            get_posible_pos(pos - 1, commands_left);
        }
        else
        {
            commands_left.pop_back();
            get_posible_pos(pos - 1, commands_left);
            get_posible_pos(pos + 1, commands_left);
        }
    }
}

int main()
{
    getline(cin, sent);
    getline(cin, recieved);

    for (auto &c : sent)
    {
        if (c == '+')
        {
            final_pos += 1;
        }
        else
        {
            final_pos -= 1;
        }
    }
    reverse(recieved.begin(), recieved.end());
    get_posible_pos(0, recieved);

    cout << fixed << setprecision(12) << correct_out / (correct_out + wrong_out) << endl;
    //cout << correct_out << endl;
    //cout << wrong_out << endl;
}