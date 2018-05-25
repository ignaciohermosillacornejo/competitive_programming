#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;
int n_lists = 0;
vector< vector < pair<int, int> > > dp;

// TODO, implement propagation
int traveldp_i(int i)
{
    cout << "i: " << i << endl;
    if (i == 0)
    {
        cnt[i] += 1;
    }
    else 
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << "i: " << i << " cnt = " << cnt[i] << endl;
            cnt[i] = cnt[i] + traveldp_i(get<1>(dp[i][j]));
            cout << "i: " << i << " cnt = " << cnt[i] << endl;
        }
        return cnt[i];
    }
}

void traveldp(int max_size, int n)
{   
    for (int i = 0; i < n; i++)
    {
        // cnt[i] = 0;
        if (get<0>(dp[i][0]) == max_size)
        {
            n_lists += int(dp[i].size());
            traveldp_i(i);
        }
    }
}

// for debuggin use
void printLIS()
{
    for (const auto & i: dp)
    {
        for (const auto & j: i)
        {
            cout << "(" << get<0>(j) << ", " << get<1>(j) << ") | ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    dp.reserve(n);

    vector <int> sequence; sequence.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(sequence));

    // We store a list of lists of tuples. Each tuple holds the length at i of 
    // the longest path and the index of the previous i of that sequence


    // element at position 1 always has a length of 1 and a previous i of 0
    dp.push_back({ { make_pair(1, -1) } });
    int max_size = 1;

    for (int i = 1; i < n; i++)
    {
        // starting option, in case no elements are added, the Lis[i] = [i]
        dp.push_back({ { make_pair(0, -1) } });
        for (int j = 0; j < i; j++)
        {
            // Check if the sequence is valid or not
            if (sequence[j] < sequence[i])
            {
                // in case the last L[j] is longer than our current option, we switch
                if (get<0>(dp[j][0]) > get<0>(dp[i][0])){
                    dp[i].clear();
                    dp[i].push_back(make_pair(get<0>(dp[j][0]), j));
                }
                // in case its the same, we add the new option
                else if (get<0>(dp[j][0]) == get<0>(dp[i][0]))
                {
                    for (const auto & k: dp[j])
                    {
                        dp[i].push_back(make_pair(get<0>(k), j));
                    }
                }
            }
        }

        for (auto & j: dp[i])
        {
            get<0>(j) = get<0>(j) + 1;
        }
        max_size = max(max_size, get<0>(dp[i][0]));
    }

    printLIS();

    for (int i = 0; i < n; i++)
    {
        cnt[i] = 0;
    }
    // Now, we can start creating the lists of the multiple max lis sequences

    traveldp(max_size, n);



    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 0)
        {
            cout << 1;
        }
        else if (cnt[i] == n_lists)
        {
            cout << 3;
        }
        else
        {
            cout << 2;
        }
    } cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << cnt[i];
    }cout << endl;



}