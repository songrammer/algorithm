#include <iostream>
using namespace std;
int N, M;
int p[501][501];
int ans = 0;
bool check(int x, int y)
{

    if (x >= 0 && x < N && y >= 0 && y < M)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void one(int x, int y, int dir)
{
    bool result = true;
    int sum = 0;
    for (int j = 0; j < 4; j++)
    {

        int nx = (dir == 1 ? x : x + j);
        int ny = (dir == 1 ? y + j : y);

        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {

            result = false;
            break;
        }
    }
    if (result)
    {

        ans = max(ans, sum);
    }
}

void two(int x, int y)
{
    bool result = true;
    int sum = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (check(x + i, y + j))
            {
                sum += p[x + i][y + j];
            }
            else
            {
                result = false;
                break;
            }
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }
}

void three(int x, int y, int dir)
{

    int dy[] = {0, -1, 1, 0};
    int dx[] = {0, 0, 0, 1};
    int dx_anti[] = {0, 0, 0, -1};

    bool result = true;
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx[i]) : (x + dy[i]);
        int ny = dir == 1 ? (y + dy[i]) : (y + dx[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }
    result = true;
    sum = 0;

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx_anti[i]) : (x + dy[i]);
        int ny = dir == 1 ? (y + dy[i]) : (y + dx_anti[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }
}

void four(int x, int y, int dir)
{

    int dx[] = {0, 0, 1, 1};
    int dy[] = {0, -1, 0, 1};

    bool result = true;
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx[i]) : (x + dy[i]);
        int ny = dir == 1 ? (y + dy[i]) : (y + dx[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }

    result = true;
    sum = 0;
    int dx_anti[] = {0, -1, 1, 0};
    int dy_anti[] = {0, 1, 0, 1};

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx_anti[i]) : (x + dy_anti[i]);
        int ny = dir == 1 ? (y + dy_anti[i]) : (y + dx_anti[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }
}

void five(int x, int y, int dir)
{

    int dx[] = {0, 0, 1, 2};
    int dy[] = {0, 1, 1, 1};

    bool result = true;
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx[i]) : (x + dy[i]);
        int ny = dir == 1 ? (y + dy[i]) : (y + dx[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }

    int dx_1[] = {0, 0, 1, 2};
    int dy_1[] = {0, -1, -1, -1};

    result = true;
    sum = 0;

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx_1[i]) : (x + dy_1[i]);
        int ny = dir == 1 ? (y + dy_1[i]) : (y + dx_1[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }

    int dx_2[] = {0, 0, -1, -2};
    int dy_2[] = {0, 1, 1, 1};

    result = true;
    sum = 0;

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx_2[i]) : (x + dy_2[i]);
        int ny = dir == 1 ? (y + dy_2[i]) : (y + dx_2[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }

    int dx_3[] = {0, 0, -1, -2};
    int dy_3[] = {0, -1, -1, -1};

    result = true;
    sum = 0;

    for (int i = 0; i < 4; i++)
    {

        int nx = dir == 1 ? (x + dx_3[i]) : (x + dy_3[i]);
        int ny = dir == 1 ? (y + dy_3[i]) : (y + dx_3[i]);
        if (check(nx, ny))
        {
            sum += p[nx][ny];
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        ans = max(ans, sum);
    }
}

int main(void)
{

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            one(i, j, 0); //1번 모양
            one(i, j, 1);

            two(i, j); //2번 모양

            three(i, j, 0); //3번 모양
            three(i, j, 1);

            four(i, j, 0); //4번 모양
            four(i, j, 1);

            five(i, j, 0); //5번 모양
            five(i, j, 1);
        }
    }
    cout << ans << '\n';

    return 0;
}