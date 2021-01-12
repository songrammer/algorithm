#include <iostream>
#include <cstring>
#define MAX 100005
using namespace std;

int main() {
   int n,s;
   int arr[MAX];
   cin >>n >>s;
   
   for(int i=0; i<n;i++){
       cin >> arr[i];
   }
   
  int res = MAX;
  int sum = 0;
  int r = 0;
  int l = 0;
 
    while (true) {
        if (sum >= s) {
            res=min(abs(r-l),res);
            sum -= arr[r++];
        }
        else if (l == n) break;
        else sum += arr[l++];
    }
    if(res==MAX){
        cout<< 0 <<'\n';
    }else{
          cout << res;
    }
  
   
  
    return 0;
}