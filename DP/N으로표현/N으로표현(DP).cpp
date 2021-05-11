#include <iostream>
#include <string>
#include <vector>
#include <vector>

using namespace std;

int solution(int N, int number)
{

    int ans = -1;
    int num[9];
    int temp = 0;

    bool result = false;

    for (int i = 0; i < 8; i++)
    {
        temp = temp * 10 + N;
        num[i + 1] = temp;
        //자리수 늘린 값들 모두 구한다음 저장
    }

    vector<int> dp[10];
    dp[0].push_back(0);
    //계산위해 0을 임의로 넣어줌

    for (int i = 1; i <= 8; i++)
    {
        //1~8까지 반복

        for (int m = 1; m <= i; m++)
        {
            //1~i자리까지 만들어 진 수 , ex)5,55,5555

            for (int k = 0; k < dp[i - m].size(); k++)
            {
                //i-m의 만큼 사용 하면 만든 값 탐색하여 m자리수 만큼의 숫자를 계산하여 i배열에 넣어줌

                dp[i].push_back(dp[i - m][k] + num[m]);
                dp[i].push_back(dp[i - m][k] - num[m]);
                dp[i].push_back(dp[i - m][k] / num[m]);
                dp[i].push_back(dp[i - m][k] * num[m]);
            }
        }

        for (int k = 0; k < dp[i].size(); k++)
        {
            if (dp[i][k] == number)
            {

                return i;
            }
        }
    }

    return ans;
}