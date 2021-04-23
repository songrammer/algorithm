#include <iostream>

using namespace std;
int N;

int total;

int sand[500][500];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool check(int x, int y)
{
    //범위 체크

    if (x >= 0 && x < N && y >= 0 && y < N)
    {

        return true;
    }
    else
    {

        return false;
    }
}

int m[4][8][2] = {
    //모래 이동 방향
    {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {-2, 0}, {2, 0}},
    {{-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 1}, {0, -2}, {0, 2}},
    {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {-2, 0}, {2, 0}},
    {{-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 1}, {0, -2}, {0, 2}},

};

double persent[4][8] = {
    //모래 양 %
    {0.1, 0.07, 0.01, 0.1, 0.07, 0.01, 0.02, 0.02},
    {0.01, 0.07, 0.1, 0.01, 0.07, 0.1, 0.02, 0.02},
    {0.01, 0.07, 0.1, 0.01, 0.07, 0.1, 0.02, 0.02},
    {0.1, 0.07, 0.01, 0.1, 0.07, 0.01, 0.02, 0.02},

};

void go(int x, int y, int k)
{

    int value = sand[x][y];

    for (int i = 0; i < 8; i++)
    {

        int nx = x + m[k][i][0];
        int ny = y + m[k][i][1];
        //해당 좌표에 따라

        int ca = (int)(sand[x][y] * persent[k][i]); //

        if (check(nx, ny))
        {
            //범위 내에 있으면
            sand[nx][ny] += ca; //모래 추가 아니면 그냥 버리면 된다.
        }

        value -= ca; //날아간 모래 양 감소
    }
    int nx;
    int ny;

    if (k == 0 || k == 2)
    {
        //5% 날아가는  부분
        nx = x;
        ny = (k == 0) ? y - 2 : y + 2;
    }
    else
    {
        //5% 날아가는  부분
        nx = (k == 3) ? x - 2 : x + 2;
        ny = y;
    }

    int ca = int(sand[x][y] * 0.05);

    if (check(nx, ny))
    {

        sand[nx][ny] += ca;
    }
    value -= ca;

    if (check(x + dx[k], y + dy[k]))
    {
        //α 위치에 남은 모래 저장
        sand[x + dx[k]][y + dy[k]] += value;
    }

    sand[x][y] = 0;
}

int main(void)
{

    cin >> N;

    total = 0;

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            cin >> sand[i][j];
            total += sand[i][j];
        }
    }

    int x = (N / 2);
    int y = (N / 2);

    int k = 0;
    int ki = 1;

    while (true)
    {

        if (ki == N)
        {
            break;
        }

        for (int l = 0; l < 2; l++)
        {
            //2번씩

            for (int cnt = 0; cnt < ki; cnt++)
            {
                //칸수 만큼 이동

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (sand[nx][ny])
                {
                    go(nx, ny, k);
                }

                x = nx;
                y = ny;
            }
            //좌표 방향 변환
            k += 1;
            k %= 4;
        }

        ki += 1;
    }

    for (int i = 0; i < N - 1; i++)
    {
        //마지막 이동

        int nx = x + dx[0];
        int ny = y + dy[0];

        if (sand[nx][ny])
        {
            go(nx, ny, k);
        }

        x = nx;
        y = ny;
    }

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        //숫자 카운팅

        for (int j = 0; j < N; j++)
        {
            result += sand[i][j];
        }
    }
    cout << total - result << '\n';

    return 0;
}