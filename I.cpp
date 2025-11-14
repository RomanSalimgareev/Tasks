#include <iostream>
#include <vector>

using namespace std;

const int N = 200001;
int idx[N + 1];
int order_vers[N + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1);
    int u, s;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> s;
        arr[u].push_back(s);
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> order_vers[i];
        idx[order_vers[i]] = i;
        ++order_vers[0];
    }


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < arr[order_vers[i]].size(); ++j)
        {
            if (idx[order_vers[i]] >= idx[arr[order_vers[i]][j]])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
