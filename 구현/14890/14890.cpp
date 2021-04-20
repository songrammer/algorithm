#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int p[101][101];
int n, l;
int visited[101][101];

bool check_num(int x, int y) //범위 넘어가는지 체크
{

    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool lean_go(int x, int y, int move_y, int move_x) //사다리 놓을 수 있는 지 체크

{
    int ki = p[x][y];
    vector<pair<int, int> > v;

    for (int i = 0; i < l; i++) //경사로 길이만큼 탐색
    {
        if (p[x][y] != ki || !check_num(x, y) || visited[x][y])
        {
            //기준점과 같이 않거나(평평한지),범위를 넘어가거나,이미 경사로를 놓았다면
            int temp = !check_num(x, y);

            return false;
        }
        else
        {
            v.push_back(make_pair(x, y)); ///가능 하면 좌표 추가
        }
        y += move_y; //행에 경사로 놓을때,
        x += move_x; //열에 경사로 놓을때
    }

    if (v.size() == l)
    {
        for (int i = 0; i < v.size(); i++) //사다리 놓음
        {

            visited[v[i].first][v[i].second] = 1;
        }
    }
    else
    {
        return false;
    }
    return true;
}

int main()
{

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cin >> p[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));

    int ans = 0;
    for (int i = 0; i < n; i++) //행 기준 탐색
    {
        bool check = true;

        for (int j = 0; j < n - 1; j++)
        {
            if (p[i][j] == p[i][j + 1]) //평평하면 통과
            {
                continue;
            }
            else
            {

                if (abs((p[i][j] - p[i][j + 1])) == 1) //차이가 1이면
                {
                    if (p[i][j] > p[i][j + 1]) //오른쪽에 경사로 놓는경우
                    {

                        if (!lean_go(i, j + 1, 1, 0)) //행애 오른쪽에 놓음
                        {

                            check = false;
                            break;
                        }
                    }
                    else
                    { //왼쪽에 경사로 놓는경우

                        if (!lean_go(i, j, -1, 0)) //행애 왼쪽에 놓음
                        {

                            check = false;
                            break;
                        }
                    }
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }
        if (check)
        {
            ;
            ans += 1;
        }
    }

    memset(visited, 0, sizeof(visited)); //경사로 초기화

    for (int j = 0; j < n; j++) //열 기준 탐색
    {
        bool check = true;

        for (int i = 0; i < n - 1; i++)
        {

            if (p[i + 1][j] == p[i][j])
            {
                continue;
            }
            else
            {

                if (abs((p[i][j] - p[i + 1][j])) == 1)
                {
                    if (p[i][j] > p[i + 1][j])
                    {

                        if (!lean_go(i + 1, j, 0, 1)) //열에 앞쪽에 놓음
                        {

                            check = false;
                            break;
                        }
                    }
                    else
                    {

                        if (!lean_go(i, j, 0, -1)) //열에 뒷쪽에 놓음
                        {

                            check = false;
                            break;
                        }
                    }
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }
        if (check)
        {

            ans += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}