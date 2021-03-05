#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int ans = 0;
bool res = true;

vector<pair<int, int> > arr;
int n;

void go(int w, int l, int h, int index)
{

	if (index == -1)
	{
		if ((long long)l * w * h > 0)
		{ //부피가 남아있으면
			res = false;
		}
		return;
	}

	if (arr[index].second != 0 && l >= arr[index].first && w >= arr[index].first && h >= arr[index].first)
	{
		// 현재 위치의 길이로 넣을 수 있을때,
		ans++;
		arr[index].second--;

		//3개로 분할한 직육면체의 각각 길이와 넓이
		go(w - arr[index].first, l, h, index);
		go(arr[index].first, l, h - arr[index].first, index);
		go(arr[index].first, l - arr[index].first, arr[index].first, index);

		return;
	}
	else
	{
		
		go(w, l, h, index - 1);
		return;
	}
}

int main()
{
	int L, W, H;
	cin >> L >> W >> H;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(pow(2, a), b));
	}

	sort(arr.begin(), arr.end());

	go(W, L, H, arr.size() - 1);

	if (!res)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << ans << '\n';
	}

	return 0;
}