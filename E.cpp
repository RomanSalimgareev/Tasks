#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1e9L + 7;
ll d[1501];
ll r[1500];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    r[0] = r[1] = 1;
    d[1] = d[2] = 1;
    for (int i = 2; i < m; ++i)
    {
        r[i] = (2 * r[i - 1]) % MOD;
        d[i + 1] = r[i];
    }


    ll v = r[m - 1];
    for (int i = 1; i < n; ++i)
    {
        ll s = 0;
        ll d_old = 0;
        for (int j = 0; j < m; ++j)
        {
            v = ((r[j] + s) % MOD + d_old) % MOD;
            r[j] = (r[j] + v) % MOD;
            s = (s + v) % MOD;
            ll tmp = d[j + 1];
            d[j + 1] = (d_old + v) % MOD;
            d_old = tmp;
        }
    }

    cout << v;
}
