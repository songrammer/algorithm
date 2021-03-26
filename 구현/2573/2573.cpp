#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int p[305][305];
int visited[305][305];
int n, m;
void BFS(int x, int y)
{

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while (!q.empty())
    {

        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {

            int nx = x + dx[k];
            int ny = y + dy[k];

            if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
                continue;
            if (visited[nx][ny] == -1 && p[nx][ny] != 0)
            {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }

    int ans = 0;

    while (true)
    {

        bool stop = false;

        memset(visited, -1, sizeof(visited));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (p[i][j] == 0) //해당 지점이 빙산인지 체크
                    continue;

                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {

                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
                        continue;
                    if (p[nx][ny] == 0) //빙산 주변이 바다인지 체크
                    {
                        cnt++;
                        stop = true; //녹는다.
                    }
                }

                p[i][j] - cnt > 0 ? p[i][j] -= cnt : p[i][j] = 0;
            }
        }

        if (!stop)
        {
            ans = 0;
            break;
        }

        ans++;

        int islands = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == -1 && p[i][j] != 0)
                {
                    BFS(i, j);
                    islands++;
                }
            }
        }

        if (islands > 1)
        {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}