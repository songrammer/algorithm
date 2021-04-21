#include <iostream>
#include <vector>

using namespace std;
struct Point
{

    int m, s, d;
};

int N, M, K;
vector<Point> map[51][51];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void move()
{
    vector<Point> temp[51][51];

    for (int i = 1; i <= N; i++)
    {

        for (int j = 1; j <= N; j++)
        {
            if (map[i][j].size())
            {
                for (int k = 0; k < map[i][j].size(); k++) //해당 좌표의 파이어 볼이 있다면,
                {
                    int s = map[i][j][k].s;
                    int cnt = s;
                    int m = map[i][j][k].m;
                    int d = map[i][j][k].d;

                    int x = i;
                    int y = j;
                    while (cnt--) //속도만큼 반복
                    {

                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) //범위내에면 이동
                        {
                            x = nx;
                            y = ny;
                        }
                        else
                        {
                            //범위를 넘어가면 각 행렬의 N에서=>1,1==>N으로 이동
                            if (nx < 1)
                            {
                                nx = N;
                            }
                            if (ny < 1)
                            {
                                ny = N;
                            }
                            if (nx > N)
                            {
                                nx = 1;
                            }
                            if (ny > N)
                            {
                                ny = 1;
                            }

                            x = nx;
                            y = ny;
                        }
                    }
                    temp[x][y].push_back({m, s, d}); //최종 결과추가
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {

        //맵에 복사

        for (int j = 1; j <= N; j++)
        {
            map[i][j] = temp[i][j];
        }
    }
}

void cal()
{

    for (int i = 1; i <= N; i++)
    {

        for (int j = 1; j <= N; j++)
        {
            if (map[i][j].size() > 1)
            {
                //한개가 아닌 여러개 있을때
                int m_sum = 0;
                int s_sum = 0;
                int odd = 0;
                int map_size = map[i][j].size();

                for (int k = 0; k < map_size; k++)
                {

                    m_sum += map[i][j][k].m; //질량들의 합
                    s_sum += map[i][j][k].s; //속도의 합

                    if ((map[i][j][k].d) % 2 == 0)
                    {
                        //방향 양수인지 체크
                        odd++;
                    }
                    else
                    {
                        //혹수인지 체크
                        odd--;
                    }
                }

                m_sum /= 5;
                s_sum /= map_size;

                map[i][j].clear(); //비워줌

                if (m_sum) //질량이 소멸되지 않을 경우
                {
                    for (int k = 0; k < 7; k += 2)
                    {
                        if (odd == map_size || -odd == map_size)
                        {
                            //방향이 홀수만 나오거나,짝수만 나올경우
                            map[i][j].push_back({m_sum, s_sum, k});
                            // 방향(0,2,4,6)으로 고정
                        }
                        else
                        {
                            map[i][j].push_back({m_sum, s_sum, k + 1});
                            // 방향(1,3,5,7)으로 고정
                        }
                    }
                }
            }
        }
    }
}
int main()
{

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {

        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        map[x][y].push_back({m, s, d});
    }

    int ans = 0;
    while (K--)
    {

        move(); //이동
        cal();  //파이어볼로 합치고 나눔
    }

    for (int i = 1; i <= N; i++)
    {
        //최종 카운팅

        for (int j = 1; j <= N; j++)
        {
            if (map[i][j].size())
            {
                for (int k = 0; k < map[i][j].size(); k++)
                {

                    ans += map[i][j][k].m;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}