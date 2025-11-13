#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int SIZE_N = 301;
const int SIZE_S = 10001;
const int INF = 1000000000;

int w[301];
int c[301];
int dp[SIZE_N][SIZE_S];

int main()
{
    ios_base::sync_with_stdio(false);
    int S, N; cin >> S >> N;

    for (int i = 1; i <= N; ++i)
        cin >> w[i];

    for (int i = 1; i <= N; ++i)
        cin >> c[i];

    vector<vector<int>> dp(N + 1, vector<int>(S + 1, -INF));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= S; ++j)
        {
            if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans_old = 0;
    int ans = 0;
    int weigth = 0;
    for (int i = 0; i <= S; ++i)
    {
        ans_old = ans;
        ans = max(ans, dp[N][i]);
        if (ans != ans_old)
            weigth = i;
    }

    vector<int> rocks;
    for (int i = N; i >= 1 && weigth >= 0; --i)
    {
        if (w[i] <= weigth && dp[i - 1][weigth - w[i]] + c[i] == dp[i][weigth])
        {
            weigth -= w[i];
            rocks.push_back(i);
        }
    }

    cout << ans << " " << rocks.size() << "\n";
    for (int i = rocks.size() - 1; i > -1; --i)
        cout << rocks[i] << " ";
}