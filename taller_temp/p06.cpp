// recursion, prunning
#include<bits/stdc++.h>
using namespace std;

// helper function
bool vowel(char letter)
{
    if (letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u')
    {
        return true;
    }
    return false;
}

// helper function
bool consonant(char letter)
{
    return not vowel(letter);
}

// necesarry for branch prunning
int count_vowels(string text)
{
    int counter = 0;
    for (char & c : text)
    {
        if (vowel(c))
        {
            counter++;
        }
    }
    cout << counter << "\n";
    return counter;
}

//recursive function, inputs the string and the number of vowels on it
int count_ways(string text, int vowel_count)
{
    //cout << vowel_count << "\n";
    // end case where we have just 1 character, one way of typing that
    // also end case where we have just constants left. 1 way of typing that
    if (text.length() == 1 or vowel_count == 0)
    {
        //cout << "a" << "\n";
        return 1;
    }
    // end case where it's not posible to type the word
    // cpci -> {}
    if (consonant(text.front()) and vowel(text.back()))
    {
        //cout << "b" << "\n";
        return 0;
    }
    // Pruning, cpcimc -> cpcim -> cpci -> {}
    if (consonant(text.front()) and consonant(text.back()) and vowel_count == 1)
    {
        //cout << "c" << "\n";
        return 0;
    }
    // recursion 1, if we have a vowel at the begining and consonant at the end
    // acmicpc -> {acmicp, cpcimc}
    if (vowel(text.front()) and consonant(text.back()))
    {
        string aux = text;
        aux.pop_back();
        reverse(text.begin(), text.end());
        text.pop_back();
        return count_ways(aux, vowel_count) + count_ways(text, vowel_count - 1);
    }
    // recursion 2, if we have a consonant at the begining and the end
    // cpcimc -> {cpcim}
    if (consonant(text.front()) and consonant(text.back()))
    {
        //cout << "e" << "\n";
        text.pop_back();
        return count_ways(text, vowel_count);
    }
    // recursion 3, if we have a vowel at the begining and end
    // acmi -> {imc}
    if (vowel(text.front()) and vowel(text.back()))
    {
        //cout << "a" << "\n";
        if (vowel(text.at(1))) // optimization so that we dont reverse twice the string
        {
            while (vowel(text.front()) and vowel(text.back()) and vowel(text.at(1)) and vowel_count > 5)
            {
                text.pop_back();
                text.erase(0, 1);
                vowel_count = vowel_count - 2;
                cout << "f" << "\n";
            }
            return count_ways(text, vowel_count);
        }
        else
        {
            //cout << "g" << "\n";
            reverse(text.begin(), text.end());
            text.pop_back();
            return count_ways(text, vowel_count - 1);
        }
    }
    throw invalid_argument( "something has gone terribly wrong");
}


int main()
{
    string input;
    int i = 1;
    while(cin >> input)
    {
        cout << i << ": " << count_ways(input, count_vowels(input)) << "\n";
        i++;
    }
}