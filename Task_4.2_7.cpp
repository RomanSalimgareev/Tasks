#include <iostream>
#include <vector>

using namespace std;

bool ways[501][501];
int arr[501][501];
int color[501];
int vertices[501];

int dfs(const int& v, bool& isCycle)
{
    int vx = 0;
    color[v] = 1;
    for (int i = 1; i <= arr[v][0]; ++i)
    {
        if (color[arr[v][i]] == 1 && ways[v][arr[v][i]])
        {
            vx = arr[v][i];
            isCycle = true;
            break;
        }
        if (color[arr[v][i]] == 0 && ways[v][arr[v][i]])
        {
            vx = dfs(arr[v][i], isCycle);
            if (isCycle)
                break;
        }
    }
    if (vx != 0)
        vertices[++vertices[0]] = v;

    if (vx == v)
        vx = 0;

    color[v] = 2;
    return vx;
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
        arr[u][++arr[u][0]] = s;
        arr[s][++arr[s][0]] = u;
        ways[u][s] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        bool cycle = false;
        dfs(i, cycle);
        if (cycle)
        {
            cout << "YES" << endl;
            cout << vertices[0] << endl;
            for (int i = vertices[0]; i > 0; --i)
                cout << vertices[i] << " ";
            return 0;
        }
    }
    cout << "NO";
}

