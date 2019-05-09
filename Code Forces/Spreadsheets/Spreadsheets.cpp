/* 
Problem: http://codeforces.com/problemset/problem/1/B
Tags: Implementation
Status: Accepted
*/

#include <bits/stdc++.h>

std::string word;
std::regex e("R[0-9]+C[0-9]+");

void convert_from_rxcy(std::string word)
{
    int array_word[8];
    int row = 0;
    int col = 0;
    int m = 0;
    for (char c : word) // we loop over the row values
    {
        if (c == 'R')
            continue; // we skip the first char
        if (c == 'C')
        {
            for (int i = 0; i < m; i++)
            {
                row += array_word[i] * pow(10, m - i - 1);
            }
            m = 0;
            memset(array_word, 0, 5);
            continue;
        }
        array_word[m] = c - '0';
        m++;
    }
    for (int i = 0; i < m; i++)
    {
        col += array_word[i] * pow(10, m - i - 1);
    }

    std::string output;
    while (col > 0)
    {
        if (col % 26 == 0)
        {
            output = 'Z' + output;
            col -= 26;
            col /= 26;
        }
        else
        {
            output = char((col % 26) + '@') + output;
            col /= 26;
        }
    }

    std::cout << output << row << "\n";
}

void convert_to_rxcy(std::string word)
{
    int col = 0;
    int row = 0;
    int array_col[10];
    int array_row[10];
    int k = 0;
    int j = 0;
    for (char c : word)
    {
        if (std::isdigit(c))
        {
            array_row[j] = c - '0';
            j++;
        }
        else
        {
            array_col[k] = c - '@';
            k++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        row += array_row[i] * pow(10, j - i - 1);
    }
    for (int i = 0; i < k; i++)
    {
        col += array_col[i] * pow(26, k - i - 1);
    }
    std::cout << 'R' << row << 'C' << col << "\n";
}

int main()
{

    int n;

    std::cin >> n;
    while (bool(n--))
    {
        std::cin >> word;
        if (std::regex_match(word, e))
        {
            convert_from_rxcy(word);
        }
        else
            convert_to_rxcy(word);
    }

    return 0;
}