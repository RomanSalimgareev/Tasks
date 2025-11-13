#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll MOD = 1000000000 + 7;
vector<ll> arr;

ll norm(const ll& val)
{
    return ((val % MOD) + MOD) % MOD;
}

ll fast_pow(ll base, ll power)
{
    base = norm(base);
    ll result = 1;
    while (power > 0) {
        if (power % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        power /= 2;
    }
    return result;
}

ll prime_div(const ll& a, const ll& b)
{
    return (a * fast_pow(b, MOD - 2)) % MOD;
}

ll factorial(ll n)
{
    ll result = 1;
    arr.resize(n + 1);
    arr[0] = 1;
    arr[1] = 1;
    for (ll i = 2; i <= n; ++i)
    {
        result = (result * i) % MOD;
        arr[i] = result;
    }

    return result;
}

ll sum(const ll& n, const ll& m, const ll& l)
{
    ll result = 0;
    ll numerator = factorial(n);
    for (ll i = 1; i <= l; ++i)
    {
        if (n < (m * i) % MOD)
            break;

        ll denom = norm(arr[n - m * i] * arr[m * i]);
        result = (result + prime_div(numerator, denom)) % MOD;
    }

    return result;
}

int main()
{
    ll n, m, l;
    cin >> n >> m >> l;
    ll result = sum(n, m, l);
    cout << result;
}
