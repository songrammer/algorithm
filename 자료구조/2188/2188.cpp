#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> a[500];
int c[500][500];
int d[500];
int f[500][500];
int n,m;
int result;
void maxFlow(int start,int end){
    
    while(1){
        fill(d,d+500,-1);
        queue <int> q;
        q.push(start);
        d[start]=start;
        while(!q.empty()){
            
            int x =q.front();
            q.pop();

            for(int i=0; i<a[x].size();i++){
                int y= a[x][i];
                if( c[x][y] - f[x][y] >0 &&d[y]==-1){
                    q.push(y);
                    d[y]=x;
                    if(y==end)break;
                }
                
            }
        }
        
        if(d[end] ==-1)break;
        
        int flow=1;
        for(int i=end; i!=start ;i=d[i]){
           f[d[i]][i]+=flow;
           f[i][d[i]]-=flow;
        }
        result+=flow;
        
    }
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
  
    cin>>n>>m;
 
    for(int i=1; i<=n;i++){
       
        a[0].push_back(i);
        c[0][i]=1;
    }
    
      for(int i=n+1; i<=n+m;i++){
       
        a[i].push_back(n+m+1);
        c[i][n+m+1]=1;
    }
    
    for(int i=1; i<=n;i++){
        int x;
        cin >>x;
        for(int j=0; j<x;j++){
            int y;
            cin >>y;
            a[i].push_back(n+y);
            c[i][n+y]=1;
            
            
        }
    }

  
    
     maxFlow(0,n+m+1);
     cout <<result<<'\n';
 
    return 0;
}