#include <iostream>
#include <vector>

using namespace std;

bool used[501];
bool have_edge[501][501];
int arr[501][501];
int numbers_edge[125001][2];
int counter = 0;

bool dfs(const int& v)
{
    used[v] = true;
    ++counter;
    for (int i = 1; i <= arr[v][0]; ++i)
    {
        if (have_edge[v][arr[v][i]] && !used[arr[v][i]])
            if (!dfs(arr[v][i])) return false;
    }

    for (int i = 1; i <= arr[v][0]; ++i)
        if (arr[v][i] && !used[arr[v][i]]) return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int u, s;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> s;
        numbers_edge[i][0] = u;
        numbers_edge[i][1] = s;
        arr[u][++arr[u][0]] = s;
        arr[s][++arr[s][0]] = u;
    }

    int q;
    cin >> q;
    int qi;
    for (int i = 1; i <= q; ++i)
    {
        cin >> qi;
        int idx_u = numbers_edge[qi][0];
        int idx_v = numbers_edge[qi][1];

        have_edge[idx_u][idx_v] = true;
        have_edge[idx_v][idx_u] = true;
    }

    bool isGood = false;
    if (q == n - 1)
    {
        for (int i = 1; i <= n && !isGood; ++i)
        {
            counter = 0;
            for (int i = 1; i <= n; ++i)
                used[i] = false;

            isGood = dfs(i) && counter == n;
        }
    }

    if (isGood) cout << "YES";
    else cout << "NO";
}

