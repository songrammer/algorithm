#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int p[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int BFS(int x, int y)
{

    int visited[51][51];
    queue<pair<int, int> > q;
    memset(visited, -1, sizeof(visited));
    

    visited[x][y] = 0;

    q.push(make_pair(x, y));

    while (!q.empty())
    {

        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (p[x][y] == 2)
        {
            return visited[x][y];
        }

        for (int i = 0; i < 4; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!(nx >= 0 && nx < n && ny >= 0 && ny < n))
                continue;

            if (visited[nx][ny] == -1 )
            {

                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main()
{

    int arr[51][51];

    cin >> n >> m;
    vector<pair<int, int> > chiken;
    vector<pair<int, int> > house;

    int ans = 100000000;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                chiken.push_back(make_pair(i, j));
            }
            else if (arr[i][j] == 1)
            {
                house.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> index;
    
    
    for (int i = 0; i < chiken.size() - m; i++)
    {
        index.push_back(0);
    }


    for (int i = 0; i < m; i++)
    {
        index.push_back(1);
    }

    

//  for (int i = 0; i < index.size(); i++)
//     {
//         cout <<index[i]<< ' ';
//     }
    // cout <<'\n';
    
    do
    {

        memcpy(p, arr, sizeof(arr));
        // cout << "pass" << '\n';
        
        //  for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {

        //         cout << p[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
// cout << "pass" << '\n';

        for (int i = 0; i < index.size(); i++)
        {
            if (index[i] == 0)
            { 
               
                // cout <<"(" <<chiken[i].first << " " << chiken[i].second <<")"<< '\n';
                p[chiken[i].first][chiken[i].second] = 0;
            }
        }
        //  cout <<"pass1"<<'\n';

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {

        //         cout << p[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        int sum = 0;
        
        for (int i = 0; i < house.size(); i++)
        {   
            // cout<<"go :"<<house[i].first<<" "<<house[i].second<<'\n';
            int result=BFS(house[i].first, house[i].second);
            // cout <<"result:"<<result<<'\n';
            sum += result;
        }
        // cout << sum << '\n';

        ans = min(sum, ans);

    } while (next_permutation(index.begin(), index.end()));
    cout << ans << '\n';

    return 0;
}