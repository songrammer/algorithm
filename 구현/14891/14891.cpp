#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int hile[101][5][9];
int n = 4;
void anti_clock(int index, int cnt) //반 시계
{
    for (int j = 0; j < 7; j++)
    {
        hile[cnt + 1][index][j] = hile[cnt][index][j + 1];
    }
    hile[cnt + 1][index][7] = hile[cnt][index][0];
}
void right_clock(int index, int cnt) //시계 방향
{
    hile[cnt + 1][index][0] = hile[cnt][index][7];
    for (int j = 1; j < 8; j++)
    {
        hile[cnt + 1][index][j] = hile[cnt][index][j - 1];
    }
}
void num_check(int index, int check[], int cnt) //톱니 바퀴 위치에 따른 좌우 탐색
{

    if (index == 0)
    {

        for (int i = 0; i < 3; i++)
        {
            if (hile[cnt][i][2] != hile[cnt][i + 1][6])
            {

                check[i + 1] = 1;
            }
            else
            {
                break;
            }
        }
    }
    else if (index == 1)
    {
        if (hile[cnt][0][2] != hile[cnt][1][6])
        {
            check[0] = 1;
        }

        for (int i = 1; i < 3; i++)
        {
            if (hile[cnt][i][2] != hile[cnt][i + 1][6])
            {
                check[i + 1] = 1;
            }
            else
            {
                break;
            }
        }
    }
    else if (index == 2)
    {
        if (hile[cnt][2][2] != hile[cnt][3][6])
        {
            check[3] = 1;
        }
        for (int i = 2; i > 0; i--)
        {
            if (hile[cnt][i - 1][2] != hile[cnt][i][6])
            {
                check[i - 1] = 1;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for (int i = 3; i > 0; i--)
        {
            if (hile[cnt][i - 1][2] != hile[cnt][i][6])
            {
                check[i - 1] = 1;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int k;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%1d", &hile[0][i][j]);
        }
    }

    cin >> k;

    int cnt = 0;

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        int check[5];

        fill(check, check + 5, 0);
        check[x] = 1;
        num_check(x, check, cnt);

        for (int i = 0; i < 4; i++)
        {
            if (check[i] == 1) //해당하는 바퀴가 회원가능하면
            {

                if (abs(x - i) % 2 == 1) //시작점과의 차이를  비교

                {
                    //반대 방향
                    if (y == 1)
                    {

                        anti_clock(i, cnt);
                    }
                    else
                    {

                        right_clock(i, cnt);
                    }
                }
                else
                {
                    //같은방향
                    if (y == 1)
                    {

                        right_clock(i, cnt);
                    }
                    else
                    {

                        anti_clock(i, cnt);
                    }
                }
            }
            else
            { //회전 불가능하면 그대로 유지

                for (int j = 0; j < 8; j++)
                {
                    hile[cnt + 1][i][j] = hile[cnt][i][j];
                }
            }
        }
        cnt += 1;
    }
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        if (hile[cnt][i][0] == 1)
        {
            sum += pow(2, i);
        }
    }
    cout << sum << '\n';
    return 0;
}