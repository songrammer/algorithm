#include <iostream>
#include <vector>
#include <queue>
#define MAX 500
using namespace std;

vector<int> a[MAX];
int c[MAX]; //왼쪽 그룹
int f[MAX]; ///오른쪽 그그룹
bool visited[MAX];

int n, m;

bool dfs(int start)
{

    visited[start] = true;
    for (int i = 0; i < a[start].size(); i++)
    {
        int next = a[start][i];
        if (f[next] == -1 || !visited[f[next]] && dfs(f[next]))
        {
            //매칭이 되지 않았거나
            //매칭이 되었지만, 다른 점과 매칭 시킬수있다면
            c[start] = next;
            f[next] = start;
            return true;
        }
    }

    return false;
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            a[i].push_back(y - 1);
        }
    }

    int ans = 0;

    fill(c, c + MAX, -1);
    fill(f, f + MAX, -1);
    for (int i = 0; i < n; i++)
    {
        if (c[i] == -1)
        {   //연결이 안되어있으면
            //배열 초기화
            fill(visited, visited + MAX, false);
            if (dfs(i))
                ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}