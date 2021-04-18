#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int room[51][51];
int R, C, T;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int ccw[] = {1, 0, 3, 2}; //반시계
int cw[] = {1, 2, 3, 0};  //시계

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
void circulate(int x, int y, int dir[]) //공기 청정기 작동 공통화
{
    int temp[51][51];

    temp[x][y] = 0;

    for (int k = 0; k < 4; k++)
    {
        while (true)
        {
            int nx = x + dx[dir[k]];
            int ny = y + dy[dir[k]];

            if (!check(nx, ny))
                break;
            if (nx == clean[0].first && ny == clean[0].second || nx == clean[1].first && ny == clean[1].second)
                break;

            temp[nx][ny] = room[x][y];
            x = nx;
            y = ny;
        }
    }
    memcpy(room, temp, sizeof(temp));
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
        circulate(clean[0].first, clean[0].second + 1, ccw); //반시계 (위)
        circulate(clean[1].first, clean[1].second + 1, cw);  //시계(아래)

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