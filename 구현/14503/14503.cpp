#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {-1, 0, 1, 0}; //북,동,남,서
int dy[] = {0, 1, 0, -1};

int main()
{

    int n, m;
    cin >> n >> m;

    int x, y, d;
    cin >> x >> y >> d;

    int p[52][52];
    int clean[52][52];
    memset(clean, 0, sizeof(clean));

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

        clean[x][y] = 1; //이동하면 청소

        bool go = false;

        int turn = d;
        for (int i = 0; i < 4; i++)
        {

            if (turn - 1 < 0)
            {
                turn = 3;
            }
            else
            {
                turn = turn - 1;
            }

            int nx = x + dx[turn];
            int ny = y + dy[turn];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && p[nx][ny] == 0 && clean[nx][ny] == 0)
            { //벽이아니고 청소하지 않았으면
                x = nx;
                y = ny;

                d = turn;
                go = true;

                break;
            }
        }

        if (!go)
        {

            int nx = x - dx[d];
            int ny = y - dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && p[nx][ny] == 0)
            {
                //끝점이 아니어도 벽일 경우에는 뒤로 못감
                x = nx;
                y = ny;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (clean[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}