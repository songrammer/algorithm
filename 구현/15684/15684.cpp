#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, h;
int result = 10;
int leg[35][35]; //사다리가 있는 행과 열의 시작 점 

bool possible(){ //사다리 타기로 같은 i에 도착하는지 검사
    
    for (int i = 1; i <= n; i++)
    {
        int cur = i;

        for (int j = 1; j <= h; j++)
        {
            // cout << "start: " << i<<" now"<<j<< '\n';
            if (cur > 1 && leg[j][cur - 1])
            {
                // cout <<"pass1"<<'\n';
               
                cur = cur - 1;
            }
            else if (leg[j][cur])
            {
                //   cout <<"pass2"<<'\n';
                cur = cur + 1;
            }
        }

        if (cur != i)
        {

             return false;
        }
    }
   return true;
    
}
 void go(int cnt,int here){
    //  cout <<" result :"<<result<<'\n';
    if(cnt>3){
        return;
    }
    
    if(possible()){
        // cout <<"cnt :"<<cnt <<'\n';
        result=min(result,cnt);
        return;
    }
   
    for(int i=here; i<=n;i++){ 
        for (int j=1 ;j<=h;j++){
           
            if( leg[j][i] || (leg[j][i-1]) ||leg[j][i+1]  )continue;
            //이미 되어있거나 오른쪽에 이미 가로선이 존재할때,
            //  cout <<"here :"<<i <<"j :"<<j <<'\n';
            leg[j][i]=1;
            go(cnt+1,i);
            leg[j][i]=0;
            
        }
    }
     
     
 }
 
int main()
{

 
    cin >> n >> m >> h;

    
    memset(leg, 0, sizeof(leg));

    for (int i = 0; i < m; i++)
    {
        
        int a, b;
        cin >> a >> b;
        leg[a][b] = 1;//사다리가 있는 행과 열의 시작 점 
        
 
    }
    
    go(0,1);
    if(result==10){
        
        cout<<-1<<'\n';
    }else{
        
        cout<<result<<'\n';
    }
   

    return 0;
}