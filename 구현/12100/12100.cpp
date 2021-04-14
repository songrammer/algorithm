#include <iostream>
#include <cstring>
using namespace std;
int N;
int ans = 0;
int dx[] = {
    -1, 0, 1, 0}; //순서대로 상우하좌 순
int dy[] = {
    0, 1, 0, -1};
bool check(int x, int y) //범위 벗어나는지 체크
{
    if (x >= 0 && x < N && y >= 0 && y < N)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void copy(int arr[25][25], int temp[25][25]) //베열 초기화 위한 함수
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = arr[i][j];
        }
    }
}

void go(int arr[25][25], int index, int dir)
{
    int visited[25][25]; //합쳐진지  확인하는 배열
    memset(visited, 0, sizeof(visited));

    if (dir == 0)
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < N; i++)
            {
                if (arr[i][j] == 0) //블록일때만 이동
                {
                    continue;
                }
                int x = i;
                int y = j;

                while (true)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (check(nx, ny)) //범위 넘으면 종료
                    {
                        break;
                    }
                    if (arr[nx][ny] == 0) //비어 있을경우 이동
                    {
                        arr[nx][ny] = arr[x][y];
                        arr[x][y] = 0;
                        x = nx;
                        y = ny;
                    }
                    else
                    {
                        if (arr[nx][ny] == arr[x][y] && visited[nx][ny] == 0) //이미 합쳐지지 않고 값이 같을 때
                        {
                            arr[nx][ny] *= 2; //합쳐준뒤에
                            visited[nx][ny] = 1;
                            arr[x][y] = 0;
                        }
                        break; //종료
                    }
                }
            }
        }
    }
    else if (dir == 1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                int x = i;
                int y = j;

                while (true)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (check(nx, ny))
                    {
                        break;
                    }
                    if (arr[nx][ny] == 0)
                    {
                        arr[nx][ny] = arr[x][y];
                        arr[x][y] = 0;
                        x = nx;
                        y = ny;
                    }
                    else
                    {
                        if (arr[nx][ny] == arr[x][y] && visited[nx][ny] == 0)
                        {
                            arr[nx][ny] *= 2;
                            visited[nx][ny] = 1;
                            arr[x][y] = 0;
                            ans = max(ans, arr[nx][ny]); //최댓값 갱신
                        }
                        break;
                    }
                }
            }
        }
    }
    else if (dir == 2)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                int x = i;
                int y = j;

                while (true)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (check(nx, ny))
                    {
                        break;
                    }
                    if (arr[nx][ny] == 0)
                    {
                        arr[nx][ny] = arr[x][y];
                        arr[x][y] = 0;
                        x = nx;
                        y = ny;
                    }
                    else
                    {
                        if (arr[nx][ny] == arr[x][y] && visited[nx][ny] == 0)
                        {
                            arr[nx][ny] *= 2;
                            visited[nx][ny] = 1;
                            arr[x][y] = 0;
                            ans = max(ans, arr[nx][ny]);
                        }
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                int x = i;
                int y = j;

                while (true)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (check(nx, ny))
                    {
                        break;
                    }
                    if (arr[nx][ny] == 0)
                    {
                        arr[nx][ny] = arr[x][y];
                        arr[x][y] = 0;
                        x = nx;
                        y = ny;
                    }
                    else
                    {
                        if (arr[nx][ny] == arr[x][y] && visited[nx][ny] == 0)
                        {
                            arr[nx][ny] *= 2;
                            visited[nx][ny] = 1;
                            arr[x][y] = 0;
                            ans = max(ans, arr[nx][ny]);
                        }
                        break;
                    }
                }
            }
        }
    }

    if (index == 5)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                ans = max(arr[i][j], ans);
            }
        }
        return;
    }

    int temp[25][25];
    copy(arr, temp);
    go(temp, index + 1, 0);

    copy(arr, temp);
    go(temp, index + 1, 1);

    copy(arr, temp);
    go(temp, index + 1, 2);

    copy(arr, temp);
    go(temp, index + 1, 3);
}
int main()
{
    cin >> N;
    int arr[25][25];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            ans = max(arr[i][j], ans);
        }
    }
    int temp[25][25];
    copy(arr, temp);
    go(temp, 1, 0);
    copy(arr, temp);
    go(temp, 1, 1);
    copy(arr, temp);
    go(temp, 1, 2);
    copy(arr, temp);
    go(temp, 1, 3);
    cout << ans << '\n';
    return 0;
}