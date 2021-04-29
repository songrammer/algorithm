#include <iostream>
#include <vector>
using namespace std;

int p[13][13];
int N;

vector<pair<int, int> > v;

bool check(int x, int y) //범위 체크
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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool connected_check(int x, int y, int k)
{
    //연결 가능한지 확인하는 함수

    while (true)
    {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (!check(nx, ny)) //범위를 넘어갈때까지 전선 연결 가능
        {

            break;
        }

        if (p[nx][ny]) //중간에 전선이 있어서 연결 불가한 경우
        {

            return false;
        }
        x = nx;
        y = ny;
    }

    return true;
}

int draw(int x, int y, int k)
{

    int count = 0; //전선길이 카운팅

    while (true)
    {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (!check(nx, ny))
        {

            break;
        }

        p[nx][ny] = 2; //2로 코어와 구분

        x = nx;
        y = ny;
        count++;
    }

    return count;
}

void init(int x, int y, int k)
{

    //연결한 전선 초기화
    while (true)
    {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (!check(nx, ny))
        {

            break;
        }

        p[nx][ny] = 0;

        x = nx;
        y = ny;
    }
}

int core = 0;

int ans = 0;

void go(int cnt, int start, int value)
{

    if (core > cnt + (v.size() - start))
    {

        return;
    }

    if (core < cnt) //코어가 더 클때
    {

        core = cnt;
        ans = value; //전선 길이 저장
    }
    else if (core == cnt)

    {
        //같다면, 최솟값 업데이트
        ans = min(value, ans);
    }

    for (int i = start; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;

        for (int k = 0; k < 4; k++)
        {
            //상하 좌우 탐색

            if (connected_check(x, y, k))
            {
                //연결 가능하면

                int count = draw(x, y, k);
                //전선 연결 그림

                go(cnt + 1, i + 1, value + count);
                //재귀 진행

                init(x, y, k);
                //연결한 전선 초기화
            }
        }
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {

        cin >> N;
        v.clear();
        core = 0;
        ans = 0;

        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < N; j++)
            {
                cin >> p[i][j];
                if (p[i][j])
                {

                    if (!(i == 0 || i == N - 1 || j == 0 || j == N - 1))
                    {
                        //양 끝 지점에 있을 때를 제와하고 좌표값 넣음
                        v.push_back(make_pair(i, j));
                    }
                }
            }
        }

        go(0, 0, 0);

        cout << "#" << (test_case) << " " << ans << '\n';
    }
    return 0;
}