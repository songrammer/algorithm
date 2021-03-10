#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int visited[10005];
vector <pair <int ,int > > v[10005];
int ans=0;
int x;
void dfs(int cur,int len){
    visited[cur]=1;
    if(ans <len){ //먼 지점 좌표 구하고 더해줌
        ans=len;
        x=cur;
    }
    
    for(int i=0; i<v[cur].size();i++){
        int next= v[cur][i].first;
        if(visited[next]==0){
            dfs(next,len+v[cur][i].second);
           
            visited[next]=0;//모든 경로 탐색을 위해 
        }
    }
    
  
    
}

int main() {
    int n;
    cin >>n;
   
    for(int i=0; i<n-1;i++){
        int x,y,z;
        cin >>x >>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    
    memset(visited,0,sizeof(visited));
    dfs(1,0); //가장 먼지점 구함
    memset(visited,0,sizeof(visited));
    dfs(x,0); //먼 지점 부터 다시 먼 지점을 구함
  
    cout <<ans<<'\n';

    
    return 0;
}