#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int M = 1000;
const int N = 1000;
vector<string> field(2 * N + 1);
bool visited[2 * N + 1][2 * M + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    cin.ignore();

    char c;
    int x_S, y_S;

    for (int i = 0; i < 2 * n + 1; ++i)
    {
        string s;
        getline(cin, s);
        field[i] = s;
        for (int j = 0; j < 2 * m + 1; ++j)
        {
            if (field[i][j] == 'S')
            {
                x_S = i;
                y_S = j;
            }
        }
    }

    queue<pair<int, int>> order;
    order.push({ x_S, y_S });
    visited[x_S][y_S] = true;
    // катим утку, пока не встретим стену, если встретили противоположную, то выходим
    // если встретили боковую, то добавляем в очередь
    while (!order.empty())
    {
        auto now_cage = order.front();
        int x = now_cage.first;
        int y = now_cage.second;
        order.pop();
        if (field[x - 1][y] == '-')
        {
            int c_x = x;
            while (c_x < 2 * n)
            {
                if (field[c_x][y - 1] == '|' && !visited[c_x][y])
                {
                    visited[c_x][y] = true;
                    order.push({ c_x, y });
                }
                else if (field[c_x][y + 1] == '|' && !visited[c_x][y])
                {
                    visited[c_x][y] = true;
                    order.push({ c_x, y });
                }

                visited[c_x][y] = true;
                if (field[c_x + 1][y] == '-')
                    break;

                c_x += 2;
            }
        }

        if (field[x + 1][y] == '-')
        {
            int c_x = x;
            while (c_x > 0)
            {
                if (field[c_x][y - 1] == '|' && !visited[c_x][y])
                {
                    visited[c_x][y] = true;
                    order.push({ c_x, y });
                }
                else if (field[c_x][y + 1] == '|' && !visited[c_x][y])
                {
                    visited[c_x][y] = true;
                    order.push({ c_x, y });
                }

                visited[c_x][y] = true;
                if (field[c_x - 1][y] == '-')
                    break;

                c_x -= 2;
            }
        }

        if (field[x][y - 1] == '|')
        {
            int c_y = y;
            while (c_y < 2 * m)
            {
                if (field[x - 1][c_y] == '-' && !visited[x][c_y])
                {
                    visited[x][c_y] = true;
                    order.push({ x, c_y });
                }
                else if (field[x + 1][c_y] == '-' && !visited[x][c_y])
                {
                    visited[x][c_y] = true;
                    order.push({ x, c_y });
                }

                visited[x][c_y] = true;
                if (field[x][c_y + 1] == '|')
                    break;

                c_y += 2;
            }
        }

        if (field[x][y + 1] == '|')
        {
            int c_y = y;
            while (c_y > 0)
            {
                if (field[x - 1][c_y] == '-' && !visited[x][c_y])
                {
                    visited[x][c_y] = true;
                    order.push({ x, c_y });
                }
                else if (field[x + 1][c_y] == '-' && !visited[x][c_y])
                {
                    visited[x][c_y] = true;
                    order.push({ x, c_y });
                }

                visited[x][c_y] = true;
                if (field[x][c_y - 1] == '|')
                    break;

                c_y -= 2;
            }
        }
    }

    for (int i = 0; i < 2 * n + 1; ++i)
    {
        for (int j = 0; j < 2 * m + 1; ++j)
        {
            if (!visited[i][j] && field[i][j] == 'D')
                cout << ' ';
            else
                cout << field[i][j];
        }
        cout << "\n";
    }
}