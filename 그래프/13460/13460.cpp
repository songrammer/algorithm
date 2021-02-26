#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int d_x[]= {
	0,-1,0,1
}
;
int d_y[]= {
	-1,0,+1,0
}
;
int ans=-1;
string p[15];
int visited[15][15];

bool check(int x, int y) {
	//범위에서 벗어나는지 체크
	if(x>=0 && x<n && y>=0 && y<m) {
		return true;
	} else {
		return false;
	}
}

void dfs(int x ,int y ,int z, int l,int cnt,int pre) {
	if(cnt==10||p[z][l]=='O') {
		return;
	}
	if(p[x][y]=='O'&&p[z][l]!='O') {
		if(ans==-1 ||ans >cnt){
		    ans=cnt;
		}
		return ;
	}
	for (int i=0; i<4;i++) {
		if(i==pre) continue;
		int nrx=x;
		int nry=y;
		int nbx=z;
		int nby=l;
		
		for (int j=1; j<=10;j++) {
		    int a=x+d_x[i]*j;
		    int b=y+d_y[i]*j;
		    int c=z+d_x[i]*j;
		    int d=l+d_y[i]*j;
			if(check(a,b) ==false ||  check(c,d)==false ) break;
			
			if(p[x+d_x[i]*j][y+d_y[i]*j]=='#') {
				dfs(nrx,nry,nbx,nby,cnt+1,i);
				break;
			} else {
				nrx=x+d_x[i]*j;
				nry=y+d_y[i]*j;
			}
			if(p[z+d_x[i]*j][l+d_y[i]*j]!='#') {
				nbx=z+d_x[i]*j;
				nby=l+d_y[i]*j;
			}
			if(p[nrx][nry]=='.'&&p[nbx][nby]=='.') continue;
			if(p[nbx][nby]=='O'||p[nrx][nry]=='O') {
				dfs(nrx,nry,nbx,nby,cnt+1,i);
				break;
			}
		}
	}
}
int main() {
    
	int r_x;
	int r_y;
	int b_x;
	int b_y;
	
	cin >> n >> m;
	for (int i=0; i<n;i++) {
		cin >>p[i];
		for (int j=0; j<m;j++) {
			if(p[i][j]=='R') {
				r_x=i;
				r_y=j;
				p[i][j]='.';
			} else if(p[i][j]=='B') {
				p[i][j]='.';
			}
		}
	}
	for (int i=0;i<4;i++) {
		memset(visited,-1,sizeof(visited));
		dfs(r_x,r_y,b_x,b_y,0,i);
	}
	
	cout <<ans<<'\n';
	return 0;
}