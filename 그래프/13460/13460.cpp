#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
 
int d_x[]={0,-1,0,1};
int d_y[]={-1,0,+1,0};

string p[15];


struct Point{
    
    int x;
    int y;
    string route;
    
};


bool check(int x, int y) {
	//범위에서 벗어나는지 체크
	if(x>=0 && x<n && y>=0 && y<m) {
		return true;
	} else {
		return false;
	}
}

int main() {
    
    int r_x;
    int r_y;
    
    
    int b_x;
    int b_y;
    
    cin >> n >> m;
    
    
    for(int i=0; i<n;i++){
        cin >>p[i];
        for(int j=0; j<m;j++){
            
            if(p[i][j]=='R'){
                r_x=i;
                r_y=j;
                p[i][j]='.';
                
            }else if(p[i][j]=='B'){
                 p[i][j]='.';
            }
            
        }
    }
    
 
    queue <Point> q;
    q.push({r_x,r_y,""});
    int visited[15][15];
    
    memset(visited,-1,sizeof(visited));
    visited[r_x][r_y]=1;
    
    
   
    
    vector <string > routes;
     
    while(!q.empty()){
        
        int x=q.front().x;
        int y=q.front().y;
        string route=q.front().route;
        q.pop();
        cout <<"x:"<<x <<" y:"<<y<<" route"<<route<<'\n';
        
        if(p[x][y]=='O'){
            if(route.length()<=10){
                cout <<"finished"<<'\n';
                cout <<x<< " "<<y <<" arrive_route:"<<route<<'\n';
                routes.push_back(route);
            }
            continue;
           
            
        }
        
        for(int k=0; k<4;k++){
            
            int nx=x+d_x[k];
            int ny=y+d_y[k];
            
            if(check(nx,ny)&&visited[nx][ny]==-1){
                
                if(p[nx][ny]=='.'||p[nx][ny]=='O'){
                    
                    if(route[route.length()-1]==k+'0'){
                        q.push({nx,ny,route});
                    }else{
                        string next_route=route;
                         q.push({nx,ny,next_route+=k+'0'});//다를때, 경로추가
                    }
                    if(p[nx][ny]!='O'){
                         visited[nx][ny]=1;
                    }
                   
                }
            }
            
        }
     
    }
    
    
    
    bool check=false;
    for(int i=0; i<routes.size();i++){
        string now=routes[i];
        int start_x=b_x;
        int start_y=b_y;
        check=false;
        for(int j=0; j<now.length();j++){
            while(true){
                cout <<"move"<<start_x<<" ,"<< start_y<<'\n';
                if(p[start_x][start_y]=='#'){
                    break;
                }else if(p[start_x][start_y]=='O'){
                    check=true;
                    break;
                    
                }
                start_x+=d_x[now[j]-'0'];
                start_y+=d_y[now[j]-'0'];
                  
            }
            if(check){
                break;
            }
            
        }
      
        
    }
    
    
    
    
    
    
    
    
    
    
    
   
    return 0;
}