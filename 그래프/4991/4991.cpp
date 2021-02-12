#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Point{
    int x;
    int y;
    int c;
};

int d_x[]={-1,1,0,0};
int d_y[]={0,0,-1,1};

int main() {

    while(true){
        int w,h;
        cin >>w >>h;
        if(w==0 && h==0){
            break;
        }
        int s_x,s_y;
        int cnt=0;
        string p[h+1];

        for(int i=0;i<h;i++){
            cin >>p[i];
            for (int j=0; j<p[i].size();j++){
                if(p[i][j]=='o'){
                    s_x=i;
                    s_y=j;
                }else if(p[i][j]=='*'){
                    cnt+=1;
                }
            }
         
        }
        
        queue <Point> q;
        q.push({s_x,s_y,0});
        int visited[h+1][w+1];
        memset(visited,-1,sizeof(visited));
        visited[s_x][s_y]=1;
        int ans=0;

        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int c=q.front().c;
            q.pop();
            if(cnt==0){          
                 break;
            }
            // cout<<"cur :" <<"x :"<< x <<" y :"<<y<<" time :"<<c<<'\n';
            for(int k=0; k<4;k++){
                int nx=x+d_x[k];
                int ny=y+d_y[k];
                 
                if(nx>=0 && nx <h &&ny>=0 && ny<w){
                    if(visited[nx][ny]==-1){
                        if(p[nx][ny]=='x') continue;
                        else if(p[nx][ny]=='*'){
                            // cout<<"find :" <<"nx :"<< nx <<" ny :"<<ny<<" time :"<<c+1<<'\n';
                            p[nx][ny]='.';
                            cnt-=1;
                            memset(visited,-1,sizeof(visited));
                            
                            queue <Point> temp;
                            temp.push({nx,ny,c+1});
                            q=temp;
                            
                            if(cnt==0){
                                ans=c+1;
                            }
                            break;
                        }else{
                            //  cout<<"nx :"<< nx <<" ny :"<<ny<<" time :"<<c+1<<'\n';
                             q.push({nx,ny,c+1});
                        }
                        
                         visited[nx][ny]=1;
                    }
                }
            }
            
        }
        if(cnt!=0){
            cout<<-1<<'\n';
        }else{
            cout<<ans<<"\n";
        }
        
        
    }
  
    return 0;
}