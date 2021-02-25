#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int dx[]= {
	-1,+1,0,0,-1,+1
}
;
int dy[]= {
	0,0,-1,+1,+1,-1
}
;
int main() {
	int n;
	cin >>n;
	string arr[51];
	int visited [51][51];
	vector <pair <int ,int > >v;
	for (int i=0; i<n;i++) {
		cin >>arr[i];
		for (int j=0; j<n;j++) {
			if(arr[i][j]=='X') {
				v.push_back(make_pair(i,j));
			}
		}
	}
	int start=0;
	memset(visited,-1,sizeof(visited));
	if(v.size()) {
		for (int i=0; i< v.size();i++) {
			if(visited[v[i].first][v[i].second]==-1) {
				visited[v[i].first][v[i].second]=start;
			}
// 			cout <<v[i].first<<" " << v[i].second<<"visited "<<  visited[v[i].first][v[i].second]<<'\n';
			for (int j=i+1; j<v.size();j++) {
				int next_x=v[j].first;
				int next_y=v[j].second;
				bool check=false;
				for (int k=0; k<6;k++) {
					int nx=v[i].first+dx[k];
					int ny=v[i].second+dy[k];
					if(next_x==nx && ny==next_y) {
						check=true;
						break;
					}
				}
				if(!check) {
					visited[next_x][next_y]=visited[v[i].first][v[i].second];
				}
			}
			start=(visited[v[i].first][v[i].second]+1)%3;
		}
	}
	int ans=0;
	int num[3]={0,};
	for (int i=0; i<n;i++) {
		for (int j=0; j<n;j++) {
		    if(visited[i][j]!=-1){
		        if(!num[visited[i][j]]){
		            num[visited[i][j]]=1;
		            ans++;
		        }
		      
		    }
		
		}
	
	}
	cout<< ans<<'\n';

	return 0;
}