#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int r, c;

struct Point
{
    int s, d, z;
};

Point map[101][101]; //상어 저장을 위한 판

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

void move()
{

    Point temp[101][101]; //같은 배열에 넣으면 이동하면서 꼬일 수 있으므로 새로 만들어줌
    memset(temp, 0, sizeof(temp));

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (map[i][j].z) //해당하는 공간에 상어가 있다면,
            {
                int x = i;
                int y = j;
                int s = map[i][j].s;
                int d = map[i][j].d;
                int z = map[i][j].z;
                int nx;
                int ny;
                map[i][j] = {0, 0, 0};

                int cnt = s;

                while (cnt) //s만큼 이동해줌
                {

                    nx = x + dx[d] * cnt;
                    ny = y + dy[d] * cnt;
                    if (nx >= 1 && nx <= r && ny >= 1 && ny <= c) //범위를 안 넘으면 그냥이동
                    {
                        x = nx;
                        y = ny;
                        cnt = 0;
                    }
                    else
                    {
                        //범위를 넘으면 이동할 방향의 끝 지점으로 이동

                        if (d < 3)
                        {
                            if (d == 1)
                            {
                                // 위로 이동하는 방향,첫번째 행 위치로 이동

                                cnt -= (x - 1);
                                x = 1;
                                d = 2;
                            }
                            else
                            {
                                // 아래로 이동하는 방향,r 위치로 이동
                                cnt -= (r - x);
                                x = r;
                                d = 1;
                            }
                        }
                        else
                        {
                            if (d == 3)
                            {
                                // 우 이동하는 방향,c 위치로 이동

                                d = 4;
                                cnt -= (c - y);
                                y = c;
                            }
                            else
                            {
                                // 좌 이동하는 방향,첫번째 열 위치로 이동

                                d = 3;
                                cnt -= (y - 1);
                                y = 1;
                            }
                        }
                    }
                }

                if (temp[x][y].z) //해당 위치에 상어가 이미 있다면
                {
                    if (temp[x][y].z < z) //더 크기 큰 상어 남김
                    {
                        temp[x][y] = {s, d, z};
                    }
                }
                else
                {
                    //없다면 추가
                    temp[x][y] = {s, d, z};
                }
            }
        }
    }
    memcpy(map, temp, sizeof(temp));
}

int main()
{
    int m;
    cin >> r >> c >> m;
    while (m--)
    {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        map[x][y] = {s, d, z};
    }
    int ans = 0;

    for (int j = 1; j <= c; j++)
    {

        for (int i = 1; i <= r; i++) //낚시
        {
            if (map[i][j].z)
            {
                ans += map[i][j].z;
                map[i][j] = {0, 0, 0};
                break;
            }
        }

        move(); //상어 움직임
    }
    cout << ans << '\n';

    return 0;
}