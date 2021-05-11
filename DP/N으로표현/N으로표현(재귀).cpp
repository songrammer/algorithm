#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans = -1;
int result_num;
void go(int num, int N, int index)
{

    if (num == result_num)
    {
        if (ans == -1 || ans > index)
        {
            ans = index;
        }
        return;
    }

    if (index == 8)
    {
        //8자리수에 도달하면 종료
        return;
    }

    int temp = 0;
    for (int i = 1; i + index <= 8; i++)
    {

        temp = temp * 10 + N;
        //8번 숫자를 추가하기 전까지 자릿수를 늘려가며 숫자를 만들어준다.

        go(num - temp, N, index + i);
        go(num + temp, N, index + i);
        go(num / temp, N, index + i);
        go(num * temp, N, index + i);
        //늘린 숫자길이 만큼 더해준다.
    }
}

int solution(int N, int number)
{
    result_num = number;
    go(0, N, 0);

    return ans;
}