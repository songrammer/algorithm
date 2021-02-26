#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
int dx[]= {-1,+1,0,0,-1,+1};
int dy[]= {0,0,-1,+1,+1,-1};
int ans=0;
string arr[51];
int visited [51][51];

bool check(int x, int y) {
	//범위에서 벗어나는지 체크
	if(x>=0 && x<n && y>=0 && y<n) {
		return true;
	} else {
		return false;
	}
}



void dfs(int x, int y ,int start) {
	visited[x][y]=start;
	ans=max(1,ans);//색칠 했으니까
	
	for (int k=0; k<6;k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(check(nx,ny)&&arr[nx][ny]=='X') {
			if(visited[nx][ny]==-1) {
				dfs(nx,ny,1-start);
				//방문하지 않았거나 색칠 하지 않았으면 계속 진행
			}
			
			if(visited[nx][ny]!=start){//방문한 뒤이니 색이 정해져있을 것
			    ans=max(ans,2);
			}else{
			 ans=max(ans,3);
			}
			
		}
	}

	
}
int main() {
	cin >>n;
	vector <pair <int ,int > >v;
	memset(visited,-1,sizeof(visited));
	for (int i=0; i<n;i++) {
		cin >> arr[i];
		for (int j=0; j<n;j++) {
			if(arr[i][j]=='X') {
				v.push_back(make_pair(i,j));
			}
		}
	}
	memset(visited,-1,sizeof(visited));
	
	for (int i=0; i<v.size();i++) {
		int x= v[i].first;
		int y=v[i].second;
		if(visited[x][y]==-1) {
			//X표시 이고 방문안한 부분 탐색
			dfs(x,y,0);
		}
	}
	int check_num[4]= {0,};

	cout <<ans<<'\n';
	return 0;
}