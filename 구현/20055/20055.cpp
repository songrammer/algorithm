#include <iostream>
#include <cstring>
using namespace std;

int N;
int K;
int belt[2][101];
int robots[101];

void move()
{
    //로봇및 컨베이어 벨트 이동

    int temp[2][101];
    int ro[101];

    temp[1][N - 1] = belt[0][N - 1]; //첫 번째 컨베이어 벨트의 마지막을 두번째 벨트로 이동
    temp[0][0] = belt[1][0];         // 두 번째의 컨베이어 벨트를 첫번째로 이동

    ro[N - 1] = 0; //로봇 떨어짐
    ro[0] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        //첫번째 컨베이어 벨트 이동

        temp[0][i + 1] = belt[0][i];
        ro[i + 1] = robots[i]; //로봇도 함께 이동
    }

    for (int i = N - 1; i > 0; i--)
    { //두번째 컨베이어 벨트 이동

        temp[1][i - 1] = belt[1][i];
    }

    memcpy(belt, temp, sizeof(temp));
    memcpy(robots, ro, sizeof(ro));
}

int main(void)
{

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {

        cin >> belt[0][i];
    }

    for (int i = N - 1; i >= 0; i--)
    {

        cin >> belt[1][i];
    }

    int count = 1;
    int ans = 0;

    while (true)
    {

        move();

        robots[N - 1] = 0; //N-1로봇 내려감

        for (int i = N - 2; i >= 0; i--)
        {

            if (robots[i]) //로봇이 있을 때,
            {

                if (robots[i + 1] == 0 && belt[0][i + 1])
                {
                    //다음칸에 로봇이 없고 내구성이 1이상일때 , 이동
                    robots[i + 1] = robots[i];
                    robots[i] = 0;
                    belt[0][i + 1]--;

                    if (belt[0][i + 1] == 0)
                    {
                        //줄여진 내구성 카운팅
                        ans++;
                    }
                }
            }
        }

        if (robots[0] == 0 && belt[0][0])
        {
            //첫번째 로봇 추가
            robots[0] = 1;
            belt[0][0]--;

            if (belt[0][0] == 0)
            {
                ans++;
            }
        }

        if (ans >= K)
        {
            //k이상이면 스톱

            break;
        }
        count++;
    }

    cout << count << '\n';

    return 0;
}