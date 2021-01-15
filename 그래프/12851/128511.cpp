#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100001
using namespace std;
int d_x[]={-1,1}; //걸어서 이동
int main() {
    
    int n,k;

    cin >>n >>k;
    queue <int> q;
    
    int ansTime=-1;
    int ansCnt=0;
    q.push(n);
    int visited[MAX];
    
    fill_n(visited,MAX,-1); //초기화
  
   visited[n]=0; //처음 지점
   
    while(!q.empty()){
        
        int now=q.front();
        q.pop();

        if(now==k){
            if(ansTime==-1){
                ansTime=visited[now];
                ansCnt++;
            }else if(ansTime==visited[now]){
                ansCnt++;
            }
            
        }
        if(ansTime !=-1 && visited[now]>ansTime) break; //가장 빠른 시간과 가장 빠른 시간구한 다음 종료
        
        
        for(int i=0; i<3;i++){
            int next;
             if(i==2){
                 next=now*2;
             }else{
                 next=now+d_x[i];
             }
         
            if(next<0 ||next >=MAX) continue; //범위 제한
       
            
            if(visited[next]==-1||visited[next]==visited[now]+1){ //방문하지 않거나 시간이 똑같으면 넣어줌 예시 1+1, 1*2
                q.push(next);
                visited[next]=visited[now]+1;
               
            }
            
        }
    
    }
    cout <<ansTime <<'\n'<<ansCnt<<'\n';
    
    return 0;
}
