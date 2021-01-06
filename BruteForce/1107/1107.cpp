#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string n;
int m;
int ans = 0;
bool remote[10];

void go(int index, int cnt, string value)
{
    cout << index << " " << value << " : " << cnt << '\n';

    if (index == n.length())
    {
        ans = min(ans, abs(stoi(value) - stoi(n)) + cnt);
        cout << "end _result :" << abs(stoi(value) - stoi(n)) + cnt << '\n';
        return;
    }

    int x = n[index] - '0';
    cout << "pass_1" << '\n';

    while (x >= 0)
    {

        if (!remote[x])
        {
            cout << "is there " << x << '\n';
            string newValue = "";
            newValue += value;
            newValue += (x + '0');

            go(index + 1, cnt + 1, newValue);
            break;
        }
        x--;
    }
    x = n[index] - '0';
    cout << "pass_2" << '\n';
    while (x <= 9)
    {
        if (!remote[x])
        {
            cout << "is there " << x << '\n';
            string newValue = "";
            newValue += value;
            newValue += (x + '0');
            go(index + 1, cnt + 1, newValue);
            break;
        }
        x++;
    }
}

int main()
{

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        remote[x] = true;
    }

    ans = abs(stoi(n) - 100); //수동으로 다 시도해볼때,

    go(0, 0, "");

    cout << ans << '\n';

    return 0;
}