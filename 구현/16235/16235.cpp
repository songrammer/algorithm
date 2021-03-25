#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int A[15][15];

int p[15][15] = {
    0,
};

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
struct Point
{
    int x, y, age;
};

struct cmp
{
    bool operator()(const Point &u, const Point &v)
    {
        return u.age > v.age;
    }
};
int main()
{

    priority_queue<Point, vector<Point>, cmp> pq;

    int n, m, k;

    cin >> n >> m >> k;
    memset(p, 0, sizeof(p));

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
        pq.push({x, y, value});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] += 5;
        }
    }

    while (k--)
    {

        vector<Point> die;

        priority_queue<Point, vector<Point>, cmp> temp;

        while (!pq.empty()) //봄
        {

            int x = pq.top().x;
            int y = pq.top().y;
            int age = pq.top().age;
            // cout <<"x:"<<x<<" y:"<<y <<" age:"<<age<<'\n';

            pq.pop();
            // cout <<"p:"<<p[x][y]<<'\n';

            if (p[x][y] - age >= 0)
            {
                p[x][y] -= age;
                age += 1;

                // cout <<"pass1"<<'\n';
                temp.push({x, y, age});
            }
            else
            {
                // cout <<"pass2"<<'\n';
                die.push_back({x, y, age / 2});
            }
        }

        while (!temp.empty()) //삭제 및 비우기
        {

            int x = temp.top().x;
            int y = temp.top().y;
            int age = temp.top().age;

            temp.pop();

            pq.push({x, y, age});
        }

        for (int i = 0; i < die.size(); i++) //여름
        {

            int x = die[i].x;
            int y = die[i].y;
            int age = die[i].age;
            p[x][y] += age;
        }

        while (!pq.empty()) //가을
        {

            int x = pq.top().x;
            int y = pq.top().y;
            int age = pq.top().age;

            pq.pop();

            if (age % 5 == 0)
            {

                for (int i = 0; i < 8; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                    {
                        temp.push({nx, ny, 1});
                    }
                }
            }
            temp.push({x, y, age});
        }

        for (int i = 1; i <= n; i++) //겨울
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] += A[i][j];
            }
        }
        pq = temp;
    }
    cout << pq.size();

    return 0;
}