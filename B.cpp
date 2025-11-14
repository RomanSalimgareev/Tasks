#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10002;
long arr[MAX_SIZE];

int N;
int K;

int quantity_rope(const long& length)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        count += arr[i] / length;
    return count;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(begin(arr), begin(arr) + N);

    long l = 0;
    long r = arr[N - 1] + 1;
    long count = 0;
    while (l + 1 < r)
    {
        long mid = (l + r) / 2;
        count = quantity_rope(mid);
        if (count >= K)
            l = mid;
        else
            r = mid;
    }

    cout << l;
}
