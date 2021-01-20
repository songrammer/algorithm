#include <iostream>
#include <cstring>
using namespace std;
int door[27];

bool canGo(string p[],int i,int j){
  
    if(p[i][j]=='.'|| islower(p[i][j]) ||isupper(p[i][j])&&door[p[i][j]-'A']) return true;
    else return false;
}

// void searching(string p[],int n, int m){
    
//       for(int i=0; i<n;i++){
//             if(i==0||i==n-1){
//                 for(int j=0; j<m;j++){
//                     if(canGo(p,i,j)){
//                         // cout <<i<<" "<<j<<'\n';
//                     }
                    
//                 }
//             }else{
//                  if(canGo(p,i,0)){
//                         // cout <<i<<" "<<0<<'\n';
//                 }
//                  if(canGo(p,i,m-1)){
//                         // cout <<i<<" "<<m-1<<'\n';
//                 }
               
//             }
//         }
    
// }
int main() {
    int t;
    cin >>t;
    while(t--){
        
        int get=0;
        int n,m;
        int visited[101][101];
        
        cin >>n>>m;
        string p[n];
        fill_n(door,26,0);
        
        memset(visited,-1,sizeof(visited));
        
        for(int i=0; i<n;i++){
            cin >>p[i];
        }
      
        string key;
        cin >>key;
        if(key !="0"){
            for(int i=0; i<key.length();i++){
              door[key[i]-32-'A']=1;
         }
            
        }
        searching(p,n,m);
        queue <pair <int ,int > > q;
        
         for(int i=0; i<n;i++){
            if(i==0||i==n-1){
                for(int j=0; j<m;j++){
                    if(canGo(p,i,j)){
                       q.push({i,j});
                       visited[i][j]=0;
                    }
                    
                }
            }else{
                 if(canGo(p,i,0)){
                        // cout <<i<<" "<<0<<'\n';
                }
                 if(canGo(p,i,m-1)){
                        // cout <<i<<" "<<m-1<<'\n';
                }
               
            }
        }
        
      
        
        // for(int i=0; i<26;i++){
        //     cout<< door[i]<<' ';
        // }
        // cout <<'\n';
     
        
        cout <<"done"<<'\n';
        

        
    }
    return 0;
}