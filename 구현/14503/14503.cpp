#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {0, 1, 0, -1}; //북,동,남,서
int dy[] = {-1, 0, 1, 0};

int returnDir(int now)
{ // 숫자에 따라 방향 지정
    if (now == 0)
    {
        return 0;
    }
    else if (now == 1)
    {
        return 3;
    }
    else if (now == 2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int nextDir(int now){
    if (now == 0)
    {
        return 3;
    }
    else if (now == 1)
    {
        return 2;
    }
    else if (now == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{

    int n, m;
    cin >> n >> m;

    int x, y, d;
    cin >> x >> y >> d;

    int p[52][52];
    int clean[52][52];
    memset(clean, 0, sizeof(clean));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }
    int ans = 0;
    

    while (true)
    {

        clean[x][y] = 1;

        bool go = false;
        // cout <<x << " "<<y <<'\n';
        for (int i = 0; i < 4; i++)
        {   int turn=(returnDir(d) + i) % 4;
            int nx = x + dx[turn];
            int ny = y + dy[turn];
            // cout <<"nx :"<<nx <<" "<<ny <<'\n';
            if (nx>0 && nx <n-1&& ny>0 && ny <m-1 &&p[nx][ny]==0&&clean[nx][ny] == 0)
            {   x=nx;
                y=ny;
                // cout <<"di"<<(i+1)%4<<'\n';
                d=nextDir(turn);
                go = true;
              
                //  cout <<"pass"<<'\n';
                break;
               
               
            }
        }
        
        if(!go){
            // cout <<"pass"<< "di"<<d<<'\n';
           
            int nx = x - dx[nextDir(d)];
            int ny = y - dy[nextDir(d)];
            if(nx>0 && nx <n-1&& ny>0 && ny <m-1){
                x=nx;
                y=ny;
              
            }else{
                break;
            }
          
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(clean[i][j]){
                ans++;
            }  
        }
       
    }
    cout <<ans<<'\n';

    return 0;
}