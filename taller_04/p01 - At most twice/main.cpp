#include <bits/stdc++.h>

std::vector<int> arrayI; // array in (array of the input)
std::vector<int> arrayO; // array out (array of the output)
int digits[10] = {0,0,0,0,0,0,0,0,0}; // initialized with values of 0
int position = 0;
bool is_right_cero = false;
bool is_biggest_digit = false;

void loadArrays(unsigned long long input) {
    memset(digits, 0, sizeof digits);
    is_biggest_digit = false;
    arrayI.clear();
    arrayO.clear();
    is_right_cero = false;
    position = 0;


        //input = 2210102960; // 2210099887
        //input = 1; // 1
        //input = 1001223343; // 998877665
        //input = 1000000000000000000; // 998877665544332211
        //input = 20152015; // 20152015
    while (input != 0) {
        arrayI.insert(arrayI.begin(), input % 10);
        input /= 10;
    }
    for (int i = 0; i < arrayI.size(); i++) arrayO.insert(arrayO.begin(), -1);
}

void printArray()
{
    for (int i = 0; i < arrayO.size(); i++){
        std::cout << arrayO[i];
    } std::cout << std::endl;
}

void fillGreedy() {
    /* We fill the remainder of ArrayO with the highest possible numbers from
     * the current position */
    for (int i = 9; i >= 0; )
    {
        if (digits[i] < 2 and (position < arrayO.size()))
        {
            arrayO[position] = i;
            digits[i]++;
            position++;
        } else i--;
    }
}

bool checkCounter(){
    for (int i = 0; i < 10; i++){
        if (digits[i] > 2) return false;
    }
    return true;
}

bool rollBack(){

    if (arrayO[position] == 0) {
        is_right_cero = true;
        digits[0]--;
        return false;
    }

    for (int i = arrayO[position]; i >= 0; i--){

        digits[arrayO[position]]--;
        arrayO[position]--;
        if (arrayO[position] > 0) digits[arrayO[position]]++;

        if (arrayO[position] == 0){
            if (is_right_cero){
                position++;
                return true;
            }
            if (is_biggest_digit){
                return true;
            }
            return false;
        }

        if (checkCounter()){
            return true;
        }
    }
    return false;
}

void proccesArray()
{
    for (;position < arrayI.size(); position++){

        arrayO[position] = arrayI[position];
        digits[arrayI[position]]++;

        if (position == arrayI.size() - 1) is_biggest_digit = true;

        if (not checkCounter()) {

            while(not rollBack()){

                position = position - 1;

                if (position == 0 and arrayO[0] > 2){
                    digits[arrayO[position]]--;
                    arrayO[position]--;
                    digits[arrayO[position]]++;
                    position++;
                    fillGreedy();
                }
                if (position == 0 and arrayO[0] == 1){
                    digits[1]--;
                    // We must shrink in 1 the ArrayO size and fill greedy
                    arrayO.resize(arrayO.size() - 1);
                    fillGreedy();
                    return;
                }

            } // We exited rollback successfully and we fill greedy
            if (is_biggest_digit) return;
            position++;
            fillGreedy();
            return;
        }
    }
}


int main()
{

    unsigned long long U;

    while(std::cin >> U){
        loadArrays(U);
        proccesArray();
        printArray();
    }
    return 0;
}


