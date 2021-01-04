#include <iostream>
#include <vector>
#include <tuple>
#include <memory.h>
using namespace std;
int n,m;

vector <tuple<int, int ,int >> v;
vector <int> dirs;
int p[10][10];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void check(int arr[10][10],int x , int y,int dir){
    
    int a=x;
    int b=y;
    while(a >=0 && a <n && b >=0 && b <m){
        if(p[a][b]==6) break; //6이 아니면 해당 숫자 넣어주기
        arr[a][b]=p[x][y];
        a+=dx[dir];
        b+=dy[dir];
        
    }
}

int go(int index){
  
  if(v.size()==index){ //방향 정해준 뒤 한번에 이동
      int arr[10][10];
      memcpy(arr, p, sizeof(p));
     
      for(int i=0; i< v.size();i++){
            int x,y,num;
            tie(x,y,num)=v[i];

            if(num==1){
                check(arr,x,y,dirs[i]);
            }else if (num==2){
                check(arr,x,y,dirs[i]);
                check(arr,x,y,(dirs[i]+2)%4);
            }else if(num==3){
                check(arr,x,y,dirs[i]);
                check(arr,x,y,(dirs[i]+1)%4);
            }else if(num==4){
                check(arr,x,y,dirs[i]);
                check(arr,x,y,(dirs[i]+1)%4);
                check(arr,x,y,(dirs[i]+2)%4);
            }else if( num==5){
                check(arr,x,y,dirs[i]);
                check(arr,x,y,(dirs[i]+1)%4);
                check(arr,x,y,(dirs[i]+2)%4);
                check(arr,x,y,(dirs[i]+3)%4);  
            } 
      }
      
      int cnt=0;
      
      for(int i=0; i<n;i++){ //숫자 카운팅
          for(int j=0; j<m;j++){
              if(arr[i][j]==0){
                cnt ++;
              }
          }
      
      }
     
      return cnt;
      
  }
  
  int ans=100;
  for(int i=0; i<4;i++){ //
      dirs[index]=i; //모든 경우 방향 정해주기
      int temp = go(index+1);
      if( ans >temp){
          ans=temp;
      }
  }
  return ans;
  
  
}


int main() {
   
    cin >>n >>m;
  
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >>p[i][j];
            
            if(p[i][j]<6 &&p[i][j]>0){
                //CCTV 위치 별로 저장
                v.emplace_back(i,j,p[i][j]); 
                dirs.push_back(0);//방향
            }
        }
    }
    
    cout <<go(0)<<'\n';

    return 0;
}