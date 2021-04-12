#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
long long go(int start, int end)
{
    long long max_result = 0;

    if (start == end)
    {
        return v[start] * v[end];
    }
    int mid = (start + end) / 2;

    long long left_max = go(start, mid);
    long long right_max = go(mid + 1, end);

    max_result = max(left_max, right_max);

    int left = mid;
    int rihgt = mid + 1;

    long long temp_sum = (v[left] + v[rihgt]);
    long long min_index = min(v[left], v[rihgt]);

    max_result = max(temp_sum * min_index, max_result);

    while (left > start || rihgt < end)
    {

        if (left > start && (end == rihgt || v[left - 1] > v[rihgt + 1]))
        {
            temp_sum += v[--left];
            min_index = min(min_index, (long long)v[left]);
        }
        else
        {
            temp_sum += v[++rihgt];
            min_index = min(min_index, (long long)v[rihgt]);
        }

        max_result = max(max_result, (long long)temp_sum * min_index);
    }

    return max_result;
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << go(0, n - 1) << '\n';

    return 0;
}