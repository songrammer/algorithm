#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int visited[10005];
vector <pair <int ,int > > v[10005];
int dfs(int cur){
    visited[cur]=1;
    int len=0;
    
    for(int i=0; i<v[cur].size();i++){
        int next= v[cur][i].first;
        if(visited[next]==0){
            len=max(v[cur][i].second+dfs(next),len); //깊이 우선 탐색을 진행하여, 경로가 최장인점 선택
            visited[next]=0;//모든 경로 탐색을 위해 
        }
    }
    
    return len; //경로 return
    
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
    
    int ans=0;
    for(int i=1; i<=n;i++){ //모든 점을 지점으로 탐색
         
    memset(visited,0,sizeof(visited));
    ans=max(dfs(i),ans);
    
    //   cout <<"ans : "<<dfs(i)<<'\n';
    }
    cout <<ans<<'\n';
    
    
    
    return 0;
}