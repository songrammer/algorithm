#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int d_x[] = {
	0, -1, 0, 1};
int d_y[] = {
	-1, 0, +1, 0};
int ans = -1;
string p[15];
int visited[15][15];


int main()
{

	int r_x;
	int r_y;
	int b_x;
	int b_y;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		for (int j = 0; j < m; j++)
		{
			if (p[i][j] == 'R')
			{
				r_x = i;
				r_y = j;
				p[i][j] = '.';
			}
			else if (p[i][j] == 'B')
			{   b_x = i;
			    b_y = j;
				p[i][j] = '.';
			}
		}
	}

	queue<pair<int, int> > rq;
	queue<pair<int, int> > bq;
	rq.push(make_pair(r_x, r_y));
	bq.push(make_pair(b_x, b_y));

	memset(visited, -1, sizeof(visited));

	visited[r_x][r_y] = 0;

	while (!rq.empty())
	{
		r_x = rq.front().first;
		b_x = bq.front().first;

		r_y = rq.front().second;
		b_y = bq.front().second;

		rq.pop();
		bq.pop();
		
		if(visited[r_x][r_y]>10){
		    break;
		}

		if (p[r_x][r_y] == 'O')
		{   
		  //  cout <<"result:"<<r_x<<","<<r_y<<'\n';
			ans = visited[r_x][r_y];
			break;
		}

		for (int i = 0; i < 4; i++)
		{

			int nrx = r_x ;
			int nry = r_y ;
			int nbx = b_x ;
			int nby = b_y ;
// 			cout <<"dir :"<<i <<'\n';
// 			cout <<"r :"<< nrx <<" "<< nry<<'\n';
// 			cout <<"b :"<< nbx <<" "<< nby<<'\n';

			while (1)
			{

				if (p[nrx][nry] == '.')
				{
					nrx += d_x[i];
					nry += d_y[i];
				}
				else
				{
					if (p[nrx][nry] == '#')
					{ //벽을 만나면 그전으로 이동
						nrx -= d_x[i];
						nry -= d_y[i];
					}
					break; //.이 아니면 멈춤
				}
			}
		

			while (1)
			{
                // cout <<p[nbx][nby]<<'\n';
				if (p[nbx][nby] == '.')
				{
					nbx += d_x[i];
					nby += d_y[i];
				}
				else
				{
					if (p[nbx][nby] == '#')
					{
						nbx -= d_x[i];
						nby -= d_y[i];
					}
					break;
				}
			}
// 			cout <<"next_pre_r :"<< nrx <<" "<< nry<<'\n';
// 	        cout <<"next_b :"<< nbx <<" "<< nby<<"go :"<<p[nbx][nby]<< '\n';
		

			if (nbx == nrx && nby == nry)
			{ //위치가 같을 경우 위치 조정
				int red = abs(r_x - nrx) + abs(r_y - nry);
				int blue = abs(b_x - nbx) + abs(b_y - nby);
				if (red > blue)
				{   
				    // cout <<"수1"<<'\n';
					nrx -= d_x[i];
					nry -= d_y[i];
				}
				else
				{   
				    // cout <<"수2"<<'\n';
					nbx -= d_x[i];
					nby -= d_y[i];
				}
			}

	       // cout <<"next_Cr :"<< nrx <<" "<< nry<<'\n';
	       // cout <<"next_b :"<< nbx <<" "<< nby<<"go :"<<p[nbx][nby]<< '\n';
			if (p[nbx][nby] == 'O')
			{ //파란구술이 먼저 빠지거나 같이 빠지면
			 //   cout <<"이경우 거름"<<'\n';
				continue;
			}
		
			

			if (visited[nrx][nry] == -1)
			{   
			 //   cout <<"pass"<<'\n';
				rq.push(make_pair(nrx, nry));
				bq.push(make_pair(nbx, nby));
				visited[nrx][nry] = visited[r_x][r_y] + 1;
			}

		
			
		}
		
	}
	cout << ans << '\n';
	return 0;
	}