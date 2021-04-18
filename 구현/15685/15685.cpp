#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;
int map[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// 0: x좌표가 증가하는 방향 (→)
// 1: y좌표가 감소하는 방향 (↑)
// 2: x좌표가 감소하는 방향 (←)
// 3: y좌표가 증가하는 방향 (↓)

void dragon(int x, int y, int d, int g)
{
    vector<int> dir;
    dir.push_back(d);
    int nx = x;
    int ny = y;

    for (int i = 0; i < g; i++)
    { //세대 만큼 이동

        int index = dir.size();

        for (int k = index - 1; k >= 0; k--) //역순으로 탐색
        {

            nx = nx + dx[(dir[k] + 1) % 4];
            ny = ny + dy[(dir[k] + 1) % 4];

            //(탐색한 결과값 +1)%4  방향으로 좌표 이동

            map[nx][ny] = 1;

            dir.push_back((dir[k] + 1) % 4); //현재 방향 추가
        }
    }
}
int main()
{
    int n;
    memset(map, 0, sizeof(map));
    cin >> n;
    while (n--)
    {
        int x, y, d, g;

        cin >> x >> y >> d >> g;

        map[x][y] = 1; //시작 좌표

        int nx = x + dx[d];
        int ny = y + dy[d];

        // 0 ≤ g ≤ 10이기 때문에 시작 점 이후 움직인 좌표
        map[nx][ny] = 1;

        dragon(nx, ny, d, g);
    }

    int ans = 0;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)

        { //전체 탐색

            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) //정사각형 모형이면
            {

                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}