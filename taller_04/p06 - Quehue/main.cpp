#include <bits/stdc++.h>

int array[100000];

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main() {

    int n;
    std::cin >> n;

    copy_n(std::istream_iterator<int>(std::cin), n, array);

    qsort(array, n, sizeof(int), compare);

    int count = 1;
    int total_time = array[0];


    for (int i = 2; i <= n - 3; i++)
    {
        if (array[i] + array[i+1] > array[i + 2]) count++;
    }
    std::cout << n - count << "\n";
    return 0;
}
