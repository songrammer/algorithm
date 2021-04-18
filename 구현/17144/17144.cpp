#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int room[51][51];
int R, C, T;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<pair<int, int> > clean;
bool check(int x, int y)
{
    if (x >= 0 && x < R && y >= 0 && y < C)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void clean_set()
{
    for (int i = 0; i < clean.size(); i++)
    {

        room[clean[i].first][clean[i].second] = -1;
    }
}

void spread()
{
    int temp[51][51];
    memset(temp, 0, sizeof(temp));

    for (int x = 0; x < R; x++)
    {
        for (int y = 0; y < C; y++)
        {

            if (room[x][y] <= 0)
                continue;
            int cnt = 0;
            int value = room[x][y];
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (!check(nx, ny) || room[nx][ny] == -1)
                    continue;
                cnt++;

                temp[nx][ny] += (value / 5);
            }

            temp[x][y] += room[x][y] - ((value / 5)) * cnt;
        }
    }

    memcpy(room, temp, sizeof(temp));
}

void go_clean_up()
{
    int c_x = clean[0].first;
    int c_y = clean[0].second;
    for (int i = c_x - 1; i >= 0; i--)
    {

        room[i + 1][c_y] = room[i][c_y];
        room[i][c_y] = 0;
    }

    for (int j = 1; j < C; j++)
    {
        room[0][j - 1] = room[0][j];
        room[0][j] = 0;
    }

    for (int i = 1; i <= c_x; i++)
    {
        room[i - 1][C - 1] = room[i][C - 1];

        room[i][C - 1] = 0;
    }

    for (int j = C - 1 - 1; j >= 1; j--)
    {
        room[c_x][j + 1] = room[c_x][j];
        room[c_x][j] = 0;
    }
}

void go_clean_down()
{

    int c_x = clean[1].first;
    int c_y = clean[1].second;
    for (int i = c_x + 1; i <= R - 1; i++)
    {

        room[i - 1][c_y] = room[i][c_y];

        room[i][c_y] = 0;
    }

    for (int j = 1; j < C; j++)
    {
        room[R - 1][j - 1] = room[R - 1][j];
        room[R - 1][j] = 0;
    }

    for (int i = R - 1 - 1; i >= c_x; i--)
    {
        room[i + 1][C - 1] = room[i][C - 1];
        room[i][C - 1] = 0;
    }

    for (int j = C - 1 - 1; j >= 1; j--)
    {
        room[c_x][j + 1] = room[c_x][j];
        room[c_x][j] = 0;
    }
}

int main()
{

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
            {
                clean.push_back(make_pair(i, j));
            }
        }
    }

    while (T--)
    {
        spread();
        go_clean_up();
        go_clean_down();
        clean_set();
    }
    int ans = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] > 0)
            {
                ans += room[i][j];
            }
        }
    }
    cout << ans << '\n';

    return 0;
}