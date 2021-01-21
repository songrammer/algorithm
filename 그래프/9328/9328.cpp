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
bool canGo(char c,int i,int j) {
	if(c=='*'||isupper(c)&&!door[c-'A']) {
		return false;
	} 
	return true;
	
}
int main() {
	int t;
	cin >>t;
	while(t--) {
		int get=0;
		int n,m;
		int visited[105][105];
		cin >>n>>m;
		char p[105][105];
		fill_n(door,26,0);
		
		queue <pair <int, int >> capital[26];

		memset(p,'0',sizeof(p));//1.겉으로 둘러싸기 위해 초기화

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> p[i][j];
			}
		}
		
		string key;
		cin >>key;
		
		if(key !="0") {
			for (int i=0; i<key.length();i++) {
				door[key[i]-32-'A']=1;
			}
		}
		queue <pair <int ,int > > q;
		
		memset(visited,-1,sizeof(visited));
		q.push(make_pair(0,0));
		visited[0][0]=1;//2.겉으로 둘러샀으니 처음 부터 시작해도됨

		while(!q.empty()) {
			int x =q.front().first;
			int y=q.front().second;
			q.pop();
			
			for (int k=0; k<4;k++) {
				int nx=x+d_x[k];
				int ny=y+d_y[k];
			
				
				if(nx>=0&& nx<=n+1&&ny>=0&&ny<=m+1) {
				    
				    if(visited[nx][ny]!=-1) continue;

					if(canGo(p[nx][ny],nx,ny)) {
						visited[nx][ny]=1;
						if(p[nx][ny]=='$') {
							get++;
							p[nx][ny]='.';
						} else if(islower(p[nx][ny])) {

							int find_al=p[nx][ny]-32-'A';
							door[p[nx][ny]-32-'A']=1;
							p[nx][ny]='.';

							while(!capital[find_al].empty()) {//3.열렸다면, 들어갈수있는 즉, 방문했던 대문자 문만 재방문(4 참고)

								int c_x=capital[find_al].front().first;
								int c_y=capital[find_al].front().second;

								q.push(make_pair(c_x,c_y));
								capital[find_al].pop();
								memset(visited,-1,sizeof(visited));
								visited[c_x][c_y]=1;
								p[c_x][c_y]='.';
							}
						}
						q.push(make_pair(nx,ny));
					} else if(isupper(p[nx][ny])) {
						capital[p[nx][ny]-'A'].push(make_pair(nx,ny));//4.나중에 문이 열릴수도 있으니 방문한 대문자 문만 저장
						visited[nx][ny]=1;
					}
				}
			}
		}
		cout <<get <<'\n';
	}
	return 0;
}