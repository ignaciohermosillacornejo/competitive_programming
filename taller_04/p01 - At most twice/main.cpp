#include <iostream>
#include <vector>

unsigned long long input;
std::vector<int> arrayI; // array in (array of the input)
std::vector<int> arrayO; // array out (array of the output)
std::vector<int> digits(10); // initialized with values of 0
int position = 0;


void loadArrays()
{
    /* We initialize the arrays that will hold the digits
     * 2210102960-> 2210099887 *2210099887
     * 1000000000000000000 -> 998877665544332211 * 998877665544332211
     * 999999999999999999 ->  998877665544332211 * 998877665544332211
     * 1001223343 -> 998877665 * 998877665
     * 20152015 -> 20152015 * 20152015
     * 900000 -> 899877 *899877
     * 1000 -> 998 *998
     * 2122 -> 2121 *2121
     * 998877665544332212 -> 998877665544332211
     * 112233445566778899 -> 99887766554433221 *
     * */
    //std::cin >> input;
    input = 112233445566778891;
    while (input != 0) {
        arrayI.insert(arrayI.begin(), int(input % 10));
        input /= 10;
    }
    for (int i = 0; i < arrayI.size(); i++) arrayO.insert(arrayO.begin(), -1);
}

void printArray()
{
    for (int i = 0; i < arrayO.size(); i++)
    {
        std::cout << arrayO[i];
    } std::cout << std::endl;
}

void fillGreedy()
{
    /* We fill the remainder of ArrayO with the highest possible numbers from
     * the current position */
    for (int i = 9; i >= 0; )
    {
        if (digits[i] < 2 && (position < arrayO.size()))
        {
            arrayO[position] = i;
            digits[i]++;
            position++;
        } else i--;
    }
}


void moveLeft()
{
    if (position == 0 && arrayO[position] == 0){ // If we reach position 0 and value is 0, we shrink output and call greedy
        arrayO.pop_back();
        fillGreedy();
    }
    else if (arrayO[position] == 0)
    // If we reach a 0 that was beforehand, we immediately move to the left
    {
        if (arrayO[position - 1] > 1 && position == 1)
        {
            digits[arrayO[position]]--;
            digits[arrayO[position -1]]--;
            arrayO[position -1]--;
            digits[arrayO[position -1]]++;
            fillGreedy();

        } else {
            digits[arrayO[position]]--;
            position--;
            moveLeft();
        }

    }
    else if (digits[arrayO[position]] > 2){ // We remove the number and shrink it
        digits[arrayO[position]]--;
        arrayO[position]--;
        digits[arrayO[position]]++;
        moveLeft();
    } else if (position == 0)
    {
        digits[arrayO[position]]--;
        arrayO[position]--;
        moveLeft();
    } else {
        if (digits[position] <= 2 && position + 1 == arrayO.size()) return;
        digits[arrayO[position]]--;
        arrayO[position]--;
        digits[arrayO[position]]++;
        if (arrayO[position] == 0 && digits[0] <= 2)
        {
            if (arrayO[position + 1] != -1) position++;
            fillGreedy();
        }
        else
        {
            moveLeft();
        }
    }
}

void moveRight() {
    /* We check if the current digit in arrayU has been used more than twice.
     * If it has been used more than twice, then we call moveLeft(), otherwise we add
     * that digit to arrayO and call moveRight() again. We also need to check to see if
     * the program has ended */
    if (digits[arrayI[position]] < 2) {
        arrayO[position] = arrayI[position];
        digits[arrayI[position]]++;
        if (position == arrayO.size() - 1) // we've reached the end, therefore we have identical numbers
        {
            return;
        }
        position++;
        moveRight();
        return;
    }
    arrayO[position] = arrayI[position];
    digits[arrayO[position]]++;
    moveLeft();
}

int main()
{
    loadArrays();
    moveRight();
    printArray();
    return 0;
}


