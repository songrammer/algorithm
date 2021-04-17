#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

char p[55][55]; //입력 받은 숫자가 문자로 변경 된 판

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{

    cin >> n >> m;

    vector<pair<int, int> > virus;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 2)
            {
                p[i][j] = '*';
                virus.push_back(make_pair(i, j)); //바이러스 위치를 저장
            }
            else if (x == 1)
            {
                p[i][j] = '-';
            }
            else
            {
                p[i][j] = '0';
            }
        }
    }

    vector<int> selected; //조합으로 활성화 바이러스 위치를 선택 위한 배열

    for (int i = 0; i < virus.size() - m; i++)
    {

        selected.push_back(0);
    }

    for (int i = 0; i < m; i++)
    {

        selected.push_back(1);
    }
    int ans = -1;

    do
    {

        queue<pair<int, int> > q;
        int visited[55][55];
        memset(visited, -1, sizeof(visited));

        for (int i = 0; i < virus.size(); i++)
        {

            if (selected[i]) //선택된 인덱스의 저장된 좌표값의 바이러스 활성화
            {
                int x = virus[i].first;
                int y = virus[i].second;
                q.push(make_pair(x, y));
                visited[x][y] = 0;
            }
        }

        while (!q.empty()) //BFS
        {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (p[nx][ny] == '-') //벽
                    continue;
                if (visited[nx][ny] != -1) //이미 방문
                    continue;

                if (p[nx][ny] == '0') //빈공간
                {
                    visited[nx][ny] = visited[x][y] + 1;
                }
                else if (p[nx][ny] == '*') //비활성화 된 곳이어도 똑같이 진행
                {
                    visited[nx][ny] = visited[x][y] + 1;
                }
                q.push(make_pair(nx, ny));
            }
        }

        bool result = true; // 실패여부 판단 변수
        int temp = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (visited[i][j] == -1 && p[i][j] == '0') //방문하지 않았고 빈공간인 경우
                {

                    result = false;
                    break;
                }
                else if (visited[i][j] != -1 && p[i][j] != '*') //방문 했으면서 바이러스가 아닌 경우 (요구 조건이 바이러스 모두 퍼진 최소 값이기 때문)
                {

                    temp = max(temp, visited[i][j]); //최대로 걸린 시간 뽑아냄
                }
            }
        }

        if (result) //전파 실패가 아닐 경우 최솟값구하기
        {
            if (ans == -1 || temp < ans)
            {
                ans = temp;
            }
        }

    } while (next_permutation(selected.begin(), selected.end())); //조합

    cout << ans << '\n';

    return 0;
}