#include <bits/stdc++.h>

std::vector< std::string > word_list;


bool sort_function(std::string a, std::string b)
{
    return a.length() < b.length();
}

int main() {
    int worst_time = 0;
    int best_time = 0;
    int n,k;
    std::string password;
    std::cin >> n >> k ;
    n++;
    while(bool(n--))
    {
        std::string s;
        std::cin >> s;
        if (n == 0) password = std::string(s);
        else word_list.push_back(s);
    }
    std::sort (word_list.begin(), word_list.end(), sort_function);

    int p_length = int(password.length());
    int pre_counter = 0;
    int post_counter = 0;

    for (auto i = 0; i < int(word_list.size()); i++)
    {
        // TODO: 3 cases. 1 we imediatly get to the password length, 2 its in the midle, 3 ist the longest
        if (word_list[i].length() < p_length) pre_counter++;
        else if (word_list[i].length() == p_length) post_counter++;
        else break;
    }
    int k_counter = 0;
    for (int i = 0; i < pre_counter; i++)
    {
        best_time++;
        k_counter++;
        if (k_counter == k)
        {
            k_counter = 0;
            best_time += 5;
        }

    }
    worst_time = best_time;
    best_time++;
    // We have the best time so far, know we need to work on the worst time.
    for (int i = 0; i < post_counter; i++)
    {
        worst_time++;
        k_counter++;
        if (k_counter == k and i != post_counter - 1)
        {
            k_counter = 0;
            worst_time += 5;
        }
    }
    std::cout << best_time << " " << worst_time << "\n";




    return 0;
}
