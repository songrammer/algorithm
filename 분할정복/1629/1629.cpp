#include <iostream>

using namespace std;
long long go(long long A, long long B, long long C)
{
    if (B == 1)
    {
        return (A) % C;
    }
    long long mid = (B) / (long long)2;
    long long result = go(A, mid, C) % C;
    if (B % 2 == 0)
    {

        return (result * result) % C;
    }
    else
    {
        return (((result * result) % C) * (A % C)) % C;
    }
}
int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    cout << go(A, B, C);

    return 0;
}