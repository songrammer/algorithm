#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, L, R;

int g[55][55];
int visited[55][55];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool check(int x, int y) //좌표 범위 체크
{
    if (x >= 0 && x < N && y >= 0 && y < N)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool gap(int value) //인구수 차이 체크
{
    if (value >= L && value <= R)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<int, int> DFS(int x, int y, int c) //DFS를 통해 같은 연합 탐색
{

    pair<int, int> me = make_pair(g[x][y], 1); //현재 국자의 인구수
    pair<int, int> sum = make_pair(0, 0);      //default 0
    visited[x][y] = c;

    for (int k = 0; k < 4; k++)
    {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (check(nx, ny) && visited[nx][ny] == -1 && gap(abs(g[nx][ny] - g[x][y])))
        {
            pair<int, int> result = DFS(nx, ny, c);
            sum = make_pair(result.first + sum.first, result.second + sum.second); //반환된 인구수를 더해줌
        }
    }
    sum = make_pair(sum.first + me.first, sum.second + me.second); // 현재 값과 반환된 값 더해줌

    return sum;
}

int main()
{

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> g[i][j];
        }
    }

    int cnt = 2003;
    int ans = 0;

    while (cnt--)
    {
        memset(visited, -1, sizeof(visited));

        vector<pair<int, int> > result_cnt; //연합 정보 저장
        int c = 0;                          //연합 group을 식별하기 위한 라벨링
        bool go = false;                    //연합 생성 되는지 체크

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                if (visited[i][j] == -1)
                {
                    for (int k = 0; k < 4; k++)
                    {

                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (check(nx, ny) && visited[nx][ny] == -1 && gap(abs(g[nx][ny] - g[i][j])))
                        {
                            //해당 하는 좌표의 상하좌우 국가와의 인구수가 L이상 R이하 &&방문 여부 검사

                            pair<int, int> result = DFS(i, j, c);
                            result_cnt.push_back(make_pair(result.first, result.second)); //DFS 연합 국가의 총 인구수와 국가수 저장
                            go = true;
                            c++;
                        }
                    }
                }
            }
        }
        if (!go) //연합이 형성 되지 않으면 종료
        {
            break;
        }

        for (int k = 0; k < result_cnt.size(); k++)
        {

            int total = result_cnt[k].first;
            int group = result_cnt[k].second;

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)

                {

                    if (visited[i][j] == k) //방문에 저장한 라벵링과 탐색하는 연합 정보와 같으면
                    {

                        g[i][j] = (total / group); //인구수 대체
                    }
                }
            }
        }

        ans++;
    }
    cout << ans << '\n';

    return 0;
}