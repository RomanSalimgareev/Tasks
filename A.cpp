#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_RADIX = 1e8;
const int N = 10;

int main()
{
    ios_base::sync_with_stdio(0);
    long year;
    cin >> year;

    bool is_bad = true;
    while (is_bad && year < MAX_RADIX)
    {
        ++year;
        string str_year = to_string(year);
        is_bad = false;
        int arr[N] = {};
        for (long i = 0; i < str_year.length(); ++i)
        {
            char digit = str_year[i];
            int number = digit - '0';
            ++arr[number];
            if (str_year[i] == '2' || str_year[i] == '0' || arr[number] > 1)
                is_bad = true;
        }
    }

    if (year >= MAX_RADIX)
    {
        cout << -1;
        return 0;
    }
    else
        cout << year;
}