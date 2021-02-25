#include <iostream>
#include <vector>
using namespace std;
 int n;
 
int dx[]={0,+1,0};
int dy[]={0,0,+1};



bool check(int x, int y){
    if(x>=0 && x<n && y>=0 && y<n){
        return true;
    }else{
        return false;
    }
    
}

int main() {
  
	cin >>n;
	string arr[51];

	for (int i=0; i<n;i++) {
		cin >>arr[i];
	
	}
	
	int ans=0;
	
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
             int cnt=0;
            for(int k=0; k<3;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(check(nx,ny)&&arr[nx][ny]=='X'){
                    cnt++;
                }
                    
            }
   
            ans=max(cnt,ans);
            
        }
    }
    cout <<ans <<'\n';

    return 0;
}