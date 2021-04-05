#include <iostream>
#include <algorithm>
#define MAX 1000
#include <cstring>
using namespace std;
struct Point {
	int d;
	int w;
}
;
bool cmp (const Point &u,const Point &v) { 
    //점수 기준 정렬,점수가 같을때 시간 촉박한 수부터 정렬
	if(u.w> v.w) {
		return true;
	}
	if(u.w== v.w) {
		return u.d<v.d;
	}
	return false;
}
int main() {
	int n;
	cin >>n;
	int scoreDay[MAX];
	vector <Point> p;
	for (int i=0; i<n;i++) {
		int x,y;
		cin >>x >>y;
		p.push_back( {
			x,y
		}
		);
	}
	memset(scoreDay,0,sizeof(scoreDay));
	int ans=0;
	sort(p.begin(),p.end(),cmp);

	for (int i=0; i<n;i++) {
		int day=p[i].d-1;

		while(1) {
			//몇일 날 할지 정하는 과정
			if(scoreDay[day]==0 || day <0) {
                //해당 날짜에 할 과제가 없거나 당장 해야할 경우 종료
				break;
			}
			day-=1;
		}
		if(day>=0) { //기간이 안지났다면 해당 날짜에 진행
			scoreDay[day]=p[i].w;
		}
	}
	for (int i=0;i<MAX;i++) {
		ans+=scoreDay[i];
	}
	cout<<ans;
	return 0;
}