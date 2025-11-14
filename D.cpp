#include <iostream>
#include <vector>

using namespace std;

const int MODULE = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<long> dp(n + k + 1);
    vector<long> pref_sum(n + k + 1);
    string line;
    cin >> line;

    dp[k] = 1;
    pref_sum[k] = 1;
    for (int i = k + 1; i < n + k + 1; ++i)
    {
        if (line[i - k - 1] == '0')
        {
            dp[i] = ((pref_sum[i - 1] - pref_sum[i - k - 1]) % MODULE + MODULE) % MODULE;
            pref_sum[i] = (pref_sum[i - 1] + dp[i]) % MODULE;
        }
        else
        {
            dp[i] = 0;
            pref_sum[i] = pref_sum[i - 1];
        }
    }
    cout << dp[n + k];
}