#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
 
int dx[]= {
	-1,+1,0,0,-1,+1
}
;
int dy[]= {
	0,0,-1,+1,+1,-1
}
;

string arr[51];
int visited [51][51];

bool check(int x, int y){
    
    if(x>=0 && x<n && y>=0 && y<n){
        return true;
    }else{
        return false;
    }
    
}

int num_decide(int z,int o,int t){
    
    if(z==0&&o==0&&t==0){
	return 0;
	}
	else if(z==1&&o==0&&t==0){
	    return 1;
	    
	}else if(z==0&&o==0&&t==1){
	    return 1;
	    
	}else if(z==0&&o==1&&t==0){
	    return 0;
	    
	}else if(z==1&&o==1&&t==0){
	    return 2;
	}else if(z==1&&o==0&&t==1){
	    return 1;
	}else if(z==0&&o==1&&t==1){
	    return 0;
	}
    
}

void dfs(int x, int y ){
    
    visited[x][y]=4;
    
    for (int k=0; k<6;k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(check(nx,ny)&&arr[nx][ny]=='X'){
		    if(visited[nx][ny]==-1){
		        dfs(nx,ny);
		    }
		}
		
	}
	
	int zero=0;
	int one=0;
	int two=0;
	
	 for (int k=0; k<6;k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(check(nx,ny)&&arr[nx][ny]=='X'){
		   
		  if(visited[nx][ny]==0&&zero==0){
		      zero++;
		  }else if (visited[nx][ny]==1&&one==0){
		      one++;
		  }else if (visited[nx][ny]==2&&one==0){
		      two++;
		  }
		    
		}
		
	}
	
	visited[x][y]=num_decide(zero,one,two);
	
    
}

int main() {
  
	cin >>n;

	vector <pair <int ,int > >v;
    memset(visited,-1,sizeof(visited));
	for (int i=0; i<n;i++) {
	    cin >> arr[i];
	    for (int j=0; j<n;j++){
	        	if(arr[i][j]=='X') {
				v.push_back(make_pair(i,j));
	    	}
	        
	    }
	
	
	}
	
    
    
	memset(visited,-1,sizeof(visited));
	
	for(int i=0; i<v.size();i++){
	    
	    int x= v[i].first;
	    int y=v[i].second;
	    if(visited[x][y]==-1){
	        dfs(x,y);
	    }
	    
	}
	int check_num[4]={0,};

	 int ans=0;
	 
	 	
// 	for (int i=0; i<n;i++) {
	    
// 	    for (int j=0; j<n;j++){
// 	            cout <<visited[i][j]<<" ";
// 	    	}
// 	    	cout <<'\n';
	        
// 	 }
	 	
	for (int i=0; i<n;i++) {
	    
	    for (int j=0; j<n;j++){
	        if(visited[i][j]!=-1 &&check_num[visited[i][j]]==0){
	         ans+=1;   
	         check_num[visited[i][j]]=1;
	        }
	            
	    	}
	    
	    }
	    cout <<ans<<'\n';
	

    return 0;
}