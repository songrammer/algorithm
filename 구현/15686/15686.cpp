#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

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
    //조합 구하기 위해서 넣어준다.

    do
    {

        vector<int> dist(house.size(), 100000000); 
        //각 지점 마다의 길이의 최솟 값을 구하기위해 집 갯수만 큼 거리를 큰 숫자로 초기화 해준다.
        for (int i = 0; i < index.size(); i++)
        {
            if (index[i] == 1) //선택된 지점을 대상으로
            {

                int x1 = chiken[i].first;
                int y1 = chiken[i].second;
              
                for (int j = 0; j < house.size(); j++)
                {
                    int x2 = house[j].first;
                    int y2 = house[j].second;
                    dist[j] = min(dist[j], abs(x1 - x2) + abs(y1 - y2)); //거리의 최솟값을 갱신한다.
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < dist.size(); i++)
        {
            sum += dist[i];
        }
        

        ans = min(sum, ans);

    } while (next_permutation(index.begin(), index.end()));
    cout << ans << '\n';

    return 0;
}