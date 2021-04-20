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
        bool check = true;
        while (num)
        {
            if (check)
            {
                if (num / b == 0)
                {

                    num = 0;
                }
                else
                {
                    num -= b;
                }
                ans += 1;
                check = false;
                continue;
            }
            if (num / c == 0)
            {
                ans += 1;
                num = 0;
            }
            else
            {
                ans += (num / c);
                num = (num) % c;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
