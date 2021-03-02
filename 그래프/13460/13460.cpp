\#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int d_x[] = {
	0, -1, 0, 1
}
;
int d_y[] = {
	-1, 0, +1, 0
}
;
int ans = -1;
string p[15];
int visited[11][11][11][11];
struct Point {
	int rx,ry,bx,by,cnt;
}
;
int main() {
	int r_x;
	int r_y;
	int b_x;
	int b_y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		for (int j = 0; j < m; j++) {
			if (p[i][j] == 'R') {
				r_x = i;
				r_y = j;
				p[i][j] = '.';
			} else if (p[i][j] == 'B') {
				b_x = i;
				b_y = j;
				p[i][j] = '.';
			}
		}
	}
	queue<Point>  q;
	q.push( {
		r_x,r_y,b_x,b_y,0
	}
	);
	memset(visited, -1, sizeof(visited));
	visited[r_x][r_y][b_x][b_y]= 1;
	while (!q.empty()) {
		r_x = q.front().rx;
		b_x = q.front().bx;
		r_y = q.front().ry;
		b_y = q.front().by;
		int cnt=q.front().cnt;
		q.pop();
	
		if(cnt>10) {
			break;
		}
		if (p[r_x][r_y] == 'O') {
			
			ans = cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nrx = r_x ;
			int nry = r_y ;
			int nbx = b_x ;
			int nby = b_y ;
			while (1) {
				if (p[nrx][nry] == '.') {
					nrx += d_x[i];
					nry += d_y[i];
				} else {
					if (p[nrx][nry] == '#') {
						//벽을 만나면 그전으로 이동
						nrx -= d_x[i];
						nry -= d_y[i];
					}
					break;
					//.이 아니면 멈춤
				}
			}
			while (1) {
				// cout <<p[nbx][nby]<<'\n';
				if (p[nbx][nby] == '.') {
					nbx += d_x[i];
					nby += d_y[i];
				} else {
					if (p[nbx][nby] == '#') {
						nbx -= d_x[i];
						nby -= d_y[i];
					}
					break;
				}
			}
		
			if (nbx == nrx && nby == nry) {
				//위치가 같을 경우 위치 조정
				int red = abs(r_x - nrx) + abs(r_y - nry);
				int blue = abs(b_x - nbx) + abs(b_y - nby);
				if(p[nbx][nby]!='O') {  //둘이 동시에 빠지는 경우
					if (red > blue) {
						// cout <<"수1"<<'\n';
						nrx -= d_x[i];
						nry -= d_y[i];
					} else {
						// cout <<"수2"<<'\n';
						nbx -= d_x[i];
						nby -= d_y[i];
					}
				}
			}
		
			if (p[nbx][nby] == 'O') {
				//파란구술이 먼저 빠지거나 
				continue;
			}
			if (visited[nrx][nry][nbx][nby] == -1) { //4차원배열로 방문 체크
				//   cout <<"pass"<<'\n';
				q.push( {
					nrx,nry,nbx,nby,cnt+1
				}
				);
				visited[nrx][nry][nbx][nby] =  1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}