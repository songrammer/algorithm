#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
const int MAX = 1000005;
 
int N;
vector<int> v(MAX);
 
long long go(int from, int to)
{
    // 기저 사례
    if (from == to) return (long long)v[from] * v[from];
 
    int mid = (from + to) / 2;
    long long left_result = go(from, mid);
    long long right_result = go(mid + 1, to);
 
    // 왼쪽, 오른쪽 부분배열 중 최대를 찾음
    long long max_result = max(left_result, right_result);
 
    int left = mid;
    int right = mid + 1;
 
    // mid에서 시작하는 교차하는 부분 배열
    long long sum = v[left] + v[right];
    long long min_value = min(v[left], v[right]);
   

    max_result = max(max_result, sum * min_value);
 
    // 교차 하는 부분 배열에서 최대를 찾음
    while (left > from || right < to)
    {
        // 오른쪽으로 증가
        if (right < to && (left == from || v[left - 1] < v[right + 1]))
        {
            sum += v[++right];
            min_value = min(min_value, (long long)v[right]);
        }
        else    // 왼쪽으로 증가
        {
            sum += v[--left];
            min_value = min(min_value, (long long)v[left]);
        }
        long long total_result = sum * min_value;
        // 최대 값 비교
        max_result = max(max_result, total_result);
    }
    
    return max_result;
}
 
int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
 
    cin >> N;
    for (int i = 0; i <N; i++) {
    
    cin >>v[i];
        
    }
    cout << go(0, N-1);
 
    return 0;
}
