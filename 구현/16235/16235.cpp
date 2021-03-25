#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int A[15][15];

int p[15][15] = {
    0,
};

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
struct Point
{
    int x, y, age, die;
};

bool cmp(const Point &u, const Point &v)
{
    return u.age < v.age;
}

int main()
{

    vector<Point> pq;

    int n, m, k;

    cin >> n >> m >> k;
   

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, value;
        cin >> x >> y >> value;
        pq.push_back({x, y, value, 0});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = 5;
        }
    }
    sort(pq.begin(), pq.end(), cmp);

    while (k--)
    {

      
        for (int i = 0; i < pq.size(); i++)
        {

            int x = pq[i].x;
            int y = pq[i].y;
            int age = pq[i].age;
            if (pq[i].die)
                continue;

            if (p[x][y] - age >= 0)
            {
                p[x][y] -= age;
                age += 1;

                // cout <<"pass1"<<'\n';
                pq[i].age += 1;
            }
            else
            {
                // cout <<"pass2"<<'\n';
                pq[i].die = 1;
                pq[i].age/=2;
            }
        }

        sort(pq.begin(), pq.end(), cmp);

        for (int i = 0; i < pq.size(); i++)
        {

            int x = pq[i].x;
            int y = pq[i].y;
            int age = pq[i].age;
            if (pq[i].die)
            {

                p[x][y] += age;
            }
        }

        for (int i = 0; i < pq.size(); i++)
        {

            int x = pq[i].x;
            int y = pq[i].y;
            int age = pq[i].age;
            if (pq[i].die) continue;

            if (age % 5 == 0)
            {

                for (int j = 0; j < 8; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                    {
                        pq.push_back({nx, ny, 1, 0});
                    }
                }
            }
            
        }
         sort(pq.begin(), pq.end(), cmp);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] += A[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < pq.size(); i++)
    {

        int x = pq[i].x;
        int y = pq[i].y;
        int age = pq[i].age;
        if (pq[i].die)
            continue;

        ans += 1;
    }
    cout << ans << '\n';

    return 0;
}