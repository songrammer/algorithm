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
        if(!visited[next]){
            len=max(v[cur][i].second +dfs(next),len); //탐색한 경로에서 최댓값을 구함
            visited[next]=0; //다른길 탐색을 위해 visited에서 빼줌
        }
    }
    
    return len;
    
}

int main() {
    int n;
    cin >>n;
    for(int i=0; i<n;i++){
        int x,y,z;
        cin >>x >>y>>z;
        
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    
    int ans=0;
     for(int i=1; i<=n;i++){
         
    memset(visited,0,sizeof(visited));
    ans=max(dfs(i),ans);

    }
    cout <<ans<<'\n';
    
    
    
    return 0;
}