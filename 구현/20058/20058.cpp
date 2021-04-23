#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int k, Q;
int N;

int p[70][70];

int temp[70][70] = {
    0,
};

void turn(int start_x, int start_y, int bum)
{

    for (int i = 0; i < bum; i++)
    {

        for (int j = 0; j < bum; j++)
        {
            temp[start_x + j][start_y + bum - 1 - i] = p[start_x + i][start_y + j];
        }
    }
}

void divide(int start_x, int start_y, int index, int l)
{
    if (index == l) //영역이 분리 되면
    {
        turn(start_x, start_y, pow(2, index)); //회전

        return;
    }
    else
    {

        int start = 0;
        int end = pow(2, index);
        int mid = (start + end) / 2;

        //4등분
        divide(start_x, start_y, index - 1, l);
        divide(start_x, start_y + mid, index - 1, l);
        divide(start_x + (mid), start_y, index - 1, l);

        divide(start_x + (mid), start_y + mid, index - 1, l);
    }
}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void melt()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!p[i][j])
                continue;
            int count = 0;

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if (p[nx][ny])
                    {
                        count++;
                    }
                }
            }
            if (count < 3)
            {

                temp[i][j]--;
            }
        }
    }
}

int visited[70][70];

int block = 0;
void DFS(int x, int y)
{

    visited[x][y] = 1;
    block++; //칸의 갯수 카운팅

    for (int k = 0; k < 4; k++)
    {

        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (!visited[nx][ny] && p[nx][ny]) //얼음이고 방문안했으면
            {
                DFS(nx, ny);
            }
        }
    }
}

int main(void)
{

    cin >> k >> Q;

    vector<int> L;
    N = pow(2, k);
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int x;
        cin >> x;
        L.push_back(x);
    }

    for (int i = 0; i < Q; i++)
    {

        divide(0, 0, k, L[i]); //영역 구분
        memcpy(p, temp, sizeof(temp));

        melt(); //녹이기
        memcpy(p, temp, sizeof(temp));
    }

    int ans_sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans_sum += p[i][j]; //함계산
        }
    }

    int ans_block = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && p[i][j]) //DFS를 통해 덩어리 갯수 카운팅
            {
                block = 0;

                DFS(i, j);
                ans_block = max(ans_block, block); //최댓값 저장
            }
        }
    }

    cout << ans_sum << '\n'
         << ans_block << '\n';

    return 0;
}