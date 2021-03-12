#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> a[205];
int c[205][205];
int d[205];
int f[205][205];

int result;
void maxFlow(int start,int end){
    
    while(1){
        fill(d,d+205,-1);
        
        queue <int> q;
        q.push(start);
        while(!q.empty()){
            
            int x =q.front();
            q.pop();
            for(int i=0; i<a[x].size();i++){
                int y= a[x][i];
                if( c[x][y] - f[x][y] &&d[y]==-1){
                    q.push(y);
                    d[y]=x;
                    if(y==end)break;
                }
                
            }
        }
        
        if(d[end] ==-1)break;
        int flow=205;
        for(int i=end; i!=start; i=d[i]){
            flow=min(flow,c[d[i]][i]- f[d[i]][i]);
        }
        
         for(int i=end; i!=start ;i=d[i]){
           f[d[i]][i]+=flow;
           f[i][d[i]]+=flow;
        }
        result+=flow;
        
        
        
    }
    
}

int main() {
    int n,m;
    cin>>n>>m;
  
    
    for(int i=1; i<=n;i++){
       
        a[0].push_back(i);
        c[0][i]=1;
    }
    
    for(int i=1; i<=n;i++){
        int x;
        cin >>x;
        for(int j=0; j<x;j++){
            int y;
            cin >>y;
            a[i].push_back(y);
            c[i][y]=1;
            
            
        }
    }
    
     maxFlow(0,n+1);
     cout <<result<<'\n';
 
    return 0;
}