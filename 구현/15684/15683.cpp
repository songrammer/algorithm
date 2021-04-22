#include <iostream>

using namespace std;

int N, M, H;

int p[31][11];
int ans = -1;

void go(int x, int cnt)
{

    int result = 0;
    for (int j = 1; j <= N; j++)
    {
        int start = j; //시작점 저장
        for (int i = 1; i <= H; i++)
        {

            if (p[i][start] == 0) //다리 없으면 넘어감
                continue;

            if (start == 1 || start == N)
            {
                //열이 1 이거나 마지막열이면,
                //(1열이라면 =>2열로 , N열이라면 N-1로 이동)
                start = (start == 1) ? start + 1 : (start - 1);
            }
            else
            {
                //그외경우 좌우로 사다리 확인
                if (p[i][start - 1] == p[i][start]) //사다리의 시작점이 같은 지 확인
                {
                    //왼쪽으로 부터 사다리가 이어질 경우,

                    start -= 1;
                }
                else if (p[i][start + 1] == p[i][start])
                {
                    //오른쪽으로 부터 사다리가 이어질 경우
                    start += 1;
                }
            }
        }

        if (start == j) //시작점과 도착점이 같다면 카운팅
        {
            result++;
        }
    }

    if (result == N)
    {
        //모든 결과가 시작점과 도착점이 일치하면 추가한 다리 횟수 저장

        if (ans == -1)
        {
            ans = cnt;
        }
        else
        {

            ans = min(ans, cnt);
        }

        return;
    }

    if (cnt == 3)
    {
        //3번 진행 후 종료

        return;
    }

    for (int i = x; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {

            if (p[i][j] || p[i][j + 1])

            {
                //현재 위치나 그 다음 위치에 이미 있다면 넘어감
                continue;
            }
            else
            {
                //없다면,다음 열 까지 사다리 만듬

                p[i][j] = j;
                p[i][j + 1] = j;

                go(i, cnt + 1);
                p[i][j] = 0;
                p[i][j + 1] = 0;
            }
        }
    }
}

int main(void)
{

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {

        int x, y;
        cin >> x >> y;

        p[x][y] = y;
        p[x][y + 1] = y;
        //다리 입력 받을시에 시작점을 넣어 구분
    }

    go(1, 0);
    cout << ans << '\n';

    return 0;
}