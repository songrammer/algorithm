#include <iostream>
#define MOD 1000000
using namespace std;

int main() {
    long long n;
    cin >> n;
   
    int p=15*MOD/10; //피보나치의 주기
    int fibo[p+1]={0,1};
    for(int i=2; i<p;i++){ //p까지 반복
        fibo[i]=fibo[i-1]+fibo[i-2];
        fibo[i]%=MOD;
    }
    cout <<fibo[n%p];

    return 0;
}