#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool desc(int a, int b) { return a > b; }

int main()
{

    int N, K;
    cin >> N >> K;

    bool devices[K + 1];
    fill(devices, devices + K + 1, false);
    
    vector<int> order[K + 1];
    vector<int> go;
    

    for (int i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        order[x].push_back(i);
        go.push_back(x);
        
    }

    for (int i = 1; i <= K; i++)
    {
        sort(order[i].begin(), order[i].end(), desc);
    }

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < K; i++)
    {

        int now = go[i];
        if (devices[now]) 
      
        {
             
             order[now].pop_back();
            continue;
        }

        if (cnt < N)
        {
            //꽂을 수 있을 경우
            if (!devices[now])
            {
                cnt++;
                devices[now] = true;
               
            }
        }
        else
        { //꽂지 못할 경우

            int latest = -1;
            int index;

            for (int j = 1; j <= K; j++)
            {

                if (devices[j]) //사용 중인 것 중에서
                {

                    if (order[j].size() > 0)
                    
                    {
                        //가장 뒷 순서에 전기용품이나
                        int temp = order[j][order[j].size() - 1];

                        if (latest < temp)
                        {
                            latest = max(temp, latest);
                            index = j;
                        }
                    }
                    else
                    {
                        //앞으로 꽂지 않을 전기용 품

                        index = j;
                        break;
                    }
                }
            }
            //전기제품 알아낸뒤 뺀다.

            devices[index] = false;
            devices[now] = true;
           
            ans++;
           
        }
         order[now].pop_back();
    }

    cout << ans << '\n';
    return 0;
}