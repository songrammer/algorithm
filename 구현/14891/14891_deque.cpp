#include <iostream>
#include <cmath>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;

int main()
{

    deque<int> dq[5]; //qeque사용해서 앞뒤로 넣고 관리해줌
    for (int i = 1; i < 5; i++)
    {
        string s;

        cin >> s;

        for (int j = 0; j < s.length(); j++)
        {

            dq[i].push_back(s[j] - '0');
        }
    }

    int k;
    cin >> k;

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        int cur = x;
        int cur_d = y;

        queue<pair<int, int> > q;

        q.push({cur, cur_d});

        while (1) //현재 위치를 기준으로 오른쪽을 탐색해줌
        {

            if (cur == 4) //도착 지면 종료
            {
                break;
            }

            cur++;
            cur_d *= -1;

            if (dq[cur][6] != dq[cur - 1][2]) //아니면 좌우 N,S극판단
            {
                q.push({cur, cur_d});
            }
            else
            {

                break;
            }
        }

        cur = x;
        cur_d = y;

        while (1) //왼쪽 탐색
        {

            if (cur == 1)
            {

                break;
            }
            cur--;
            cur_d *= -1;

            if (dq[cur + 1][6] != dq[cur][2])
            {
                q.push({cur, cur_d});
            }
            else
            {
                break;
            }
        }

        while (!q.empty()) //회원가능한 톱니 바퀴 pop
        {

            int now = q.front().first;
            int dir = q.front().second;
            q.pop();

            if (dir == 1) //시계방향
            {

                int temp = dq[now].back(); //뒤에꺼 빼서
                dq[now].pop_back();
                dq[now].push_front(temp); //앞에 넣음
            }
            else
            {

                int temp = dq[now].front(); //앞에거 빼서
                dq[now].pop_front();
                dq[now].push_back(temp); //뒤에 넣음
            }
        }
    }

    int sum = 0;

    for (int i = 1; i < 5; i++)
    {
        if (dq[i].front() == 1)
        {
            sum += pow(2, i - 1);
        }
    }
    cout << sum << '\n';
    return 0;
}