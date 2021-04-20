#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int b, c;
    int arr[n + 5];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    cin >> b >> c;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        if (num >= b)
        {
            int d = arr[i] - b;
            ans += (d % c == 0 ? d / c : d / c + 1);
        }
    }

    cout << ans + n << '\n';

    return 0;
}
