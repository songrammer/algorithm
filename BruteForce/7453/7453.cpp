#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >>n;
	vector <int> a(n);
	vector <int> b(n);
	vector <int> c(n);
	vector <int> d(n);
	for (int i=0; i<n;i++) {
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	vector <int> arr1;
	vector <int> arr2;
	for (int i=0; i<n;i++) {
		for (int j=0; j<n;j++) {
			arr1.push_back(a[i]+b[j]);
			arr2.push_back(c[i]+d[j]);
		}
	}


	sort(arr2.begin(),arr2.end());
	
	long long ans=0;
	
	for (int i=0; i<arr1.size();i++) {
		int num=arr1[i];
		long long cnt=upper_bound(arr2.begin(), arr2.end(),-num)-lower_bound(arr2.begin(), arr2.end(),-num);
		if(cnt>0){
		    ans+=cnt;
		}
	
	}
	cout <<ans<<'\n';
	return 0;
}