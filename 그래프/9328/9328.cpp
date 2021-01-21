#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int door[27];
int d_x[]= {
	0,0,-1,1
}
;
int d_y[]= {
	-1,1,0,0
}
;
bool canGo(string p[],int i,int j) {
  
	if(p[i][j]=='*'||isupper(p[i][j])&&!door[p[i][j]-'A']) {
		return false;
	} else {
	    if(islower(p[i][j])){
	        door[p[i][j]-32-'A']=1;
	       
	    }
	    
	    return true;
	    
	}
}
int main() {
	int t;
	cin >>t;
	while(t--) {
		int get=0;
	
		int n,m;
		int visited[101][101];
		cin >>n>>m;
		string p[n];
		fill_n(door,26,0);
		for (int i=0; i<n;i++) {
			cin >>p[i];
		}
		string key;
		cin >>key;
		if(key !="0") {
			for (int i=0; i<key.length();i++) {
				door[key[i]-32-'A']=1;
			}
		}
		vector <pair <int ,int > >enter;
		for (int i=0; i<n;i++) {
			if(i==0||i==n-1) {
				for (int j=0; j<m;j++) {
					if(canGo(p,i,j)) {
						enter.push_back(make_pair(i,j));
					}
				}
			} else {
			   
				if(canGo(p,i,m-1)) {
					enter.push_back(make_pair(i,m-1));
				}
				if(canGo(p,i,0)) {
					enter.push_back(make_pair(i,0));
				}
			}
		}
	   
		int cnt=1;
		
		for (int start =0; start<cnt;start++) {
			for (int a=0; a<enter.size();a++) {
				int x=enter[a].first;
				int y=enter[a].second;
				queue <pair <int ,int > > q;
				memset(visited,-1,sizeof(visited));
				q.push(make_pair(x,y));
				visited[x][y]=1;
				while(!q.empty()) {
					int x =q.front().first;
					int y=q.front().second;
					q.pop();
				
				
					for (int k=0; k<4;k++) {
						int nx=x+d_x[k];
						int ny=y+d_y[k];
						if(nx>=0&& nx<n&&ny>=0&&ny<m) {
							if(visited[nx][ny]==-1&&canGo(p,nx,ny)) {
								if(p[nx][ny]=='$') {
									get++;
									p[nx][ny]='.';
								
								} else if(islower(p[nx][ny])) {
									door[p[nx][ny]-32-'A']=1;
									p[nx][ny]='.';
									cnt++;
								}
								visited[nx][ny]=1;
								q.push(make_pair(nx,ny));
							}
						}
					}
				}
			}
		}
		cout <<get <<'\n';
	
	}
	return 0;
}