#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string n;
int m;
int ans = 0;
bool remote[11];

int chekPosiible(int num){//리모콘으로 갈 수 있는지 확인

    int  cnt =0;
    if(num==0){ //숫자 자체가 0일때 예외 처리
		if(remote[num]){
			return 0;
		}else{
			return 1;
		}
	
	}
	
    while(num){
        
        if(remote[num%10]){
            return 0;
        }else{
            num/=10;
            cnt++;
        }
       
    }
    return cnt;
    
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

   for(int i=0; i<=1000000;i++){
       
       int check=chekPosiible(i);
       
       if(check){
           //갈수 있으면 이동한 다음 카운트
           ans=min(ans,abs(stoi(n)-i)+check);
       }
       
   }

    cout << ans << '\n';

    return 0;
}