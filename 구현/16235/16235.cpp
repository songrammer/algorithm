#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int A[15][15];

int p[15][15] = {
    0,
};

int dead[15][15] = {
    0,
};
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int main()
{
    int ans = 0;
    vector<int> pq[15][15]; //3차원 배열 좌표마다 백터값으로 넣기

    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
            p[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, value;
        cin >> x >> y >> value;
        pq[x][y].push_back(value);
        ans++;
    }

    while (k--)
    {

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= n; j++)
            {

                sort(pq[i][j].begin(), pq[i][j].end()); //해당 좌표에 있는 나무들 정렬
                p[i][j] += dead[i][j];                  //양분 추가(가을) 따로 빼도 상관무이다.
                dead[i][j] = 0;                         //초기화
            }
        }

        for (int i = 1; i <= n; i++) //봄 
        {

            for (int j = 1; j <= n; j++)
            {

                for (int z = 0; z < pq[i][j].size(); z++)
                {
                    if (p[i][j] - pq[i][j][z] >= 0)
                    {
                        p[i][j] -= pq[i][j][z]; 
                        pq[i][j][z] += 1;
                    }
                    else
                    {

                        for (int a = pq[i][j].size() - 1; a >= z; a--)
                        {
                            dead[i][j] += int(pq[i][j][a] / 2);
                            pq[i][j].pop_back(); //부족한 지점이 있으면 그 점 포함 그 뒤로 모두 불가능하다.
                            ans--;
                        }
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) //가을
        {

            for (int j = 1; j <= n; j++)
            {

                for (int z = 0; z < pq[i][j].size(); z++)
                {
                    if (pq[i][j][z] % 5 == 0)
                    {

                        for (int a = 0; a < 8; a++)
                        {
                            int nx = i + dx[a];
                            int ny = j + dy[a];
                            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                            {
                                pq[nx][ny].push_back(1); 
                                ans++;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) //겨울 양분 더 해줌
        {

            for (int j = 1; j <= n; j++)
            {

                p[i][j] += A[i][j];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}