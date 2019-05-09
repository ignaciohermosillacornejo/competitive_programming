/*
Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=5215&mosmsg=Submission+received+with+ID+2543598
Tags: Implementation
Status: Accepted
*/

#include <bits/stdc++.h>

std::vector<int> arrayI;                      // array in (array of the input)
std::vector<int> arrayO;                      // array out (array of the output)
int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // initialized with values of 0
int position = 0;
bool greedy_flag;

void loadArrays(unsigned long long input)
{
    memset(digits, 0, sizeof digits);
    arrayI.clear();
    arrayO.clear();
    greedy_flag = true;
    position = 0;

    //input = 2210102960; // 2210099887
    //input = 1; // 1
    //input = 1001223343; // 998877665
    //input = 1000000000000000000; // 998877665544332211
    //input = 20152015; // 20152015
    while (input != 0)
    {
        arrayI.insert(arrayI.begin(), input % 10);
        input /= 10;
    }
    for (int i = 0; i < arrayI.size(); i++)
        arrayO.insert(arrayO.begin(), -1);
}

void printArray()
{
    for (int i = 0; i < arrayO.size(); i++)
    {
        std::cout << arrayO[i];
    }
    std::cout << std::endl;
}

void fillGreedy()
{
    /* We fill the remainder of ArrayO with the highest possible numbers from
     * the current position */
    for (int i = 9; i >= 0;)
    {
        if (digits[i] < 2 and (position < arrayO.size()))
        {
            arrayO[position] = i;
            digits[i]++;
            position++;
        }
        else
            i--;
    }
}

bool checkCounter()
{
    for (int i = 0; i < 10; i++)
    {
        if (digits[i] > 2)
            return false;
    }

    return true;
}

void rollBack()
{

    //std::cout << "position: " << position << "  g_flag: " << greedy_flag << "\n";
    //for (int i = 0; i < 10; i++){
    //    std::cout << digits[i] << " ";
    //} std::cout << "\n";

    // base case 1, we've reached the position 0 and the value is 1, we must decrement the output array and do greedy
    if (position == 0 and arrayO[0] == 1)
    {
        digits[1]--;
        arrayO.resize(arrayO.size() - 1);
        fillGreedy();
    }

    // case 1, we have a valid number which we can do greedy on. It is also our exit case so we dont need to call
    // recursively at the end.
    else if (checkCounter() and greedy_flag)
    {
        position++;
        fillGreedy();
    }

    // case 2, we have a valid number on which we can't do greedy so me must decrement the current digit
    else if (checkCounter() and not greedy_flag)
    {

        // case 2.1 the current position is 0, this can happen if we just moved to the number and if happened to be 0
        // or if we decremented the digit from 1 to 0.
        if (arrayO[position] == 0)
        {
            digits[arrayO[position]]--;
            position--;
            rollBack();
        }

        else if (position == 0 and arrayO[position] > 1)
        {
            digits[arrayO[position]]--;
            arrayO[position]--;
            digits[arrayO[position]]++;
            position++;
            fillGreedy();
        }

        // case 2.3 the current number is 1 or greater, so the greedy_flag is removed
        else
        {
            digits[arrayO[position]]--;
            arrayO[position]--;
            digits[arrayO[position]]++;
            greedy_flag = true;
            rollBack();
        }
    }

    // case 3, we have an invalid number
    else if (not checkCounter())
    {

        //case 3.1 if our current digit is 0, we need to move left
        if (arrayO[position] == 0)
        {
            greedy_flag = false;
            digits[arrayO[position]]--;
            position--;
            rollBack();
        }

        //case 3.2 our current digit is 1 or more, we decrement it and call rollback again
        else if (arrayO[position] > 0)
        {
            digits[arrayO[position]]--;
            arrayO[position]--;
            digits[arrayO[position]]++;
            rollBack();
        }
    }
}

void proccesArray()
{
    for (; position < arrayI.size(); position++)
    {

        arrayO[position] = arrayI[position];
        digits[arrayI[position]]++;

        if (not checkCounter())
        {
            rollBack();
            return;
        }
    }
}

int main()
{

    unsigned long long U;

    while (std::cin >> U)
    {
        loadArrays(U);
        proccesArray();
        printArray();
    }
    return 0;
}
