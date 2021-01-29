#include <iostream>
#include <vector>

#include <cstring>
#define MAX 405

using namespace std;
int result_print(int num) {

    if (num) {
        if (num > 0) return 1;
        else return -1;

    } else {
        return 0;
    }

}


int main() {

    int n, k, s;
    int value[MAX][MAX];
    
    memset(value, 0, sizeof(value));
    
    vector < pair < int, int > > a;
   
    cin >> n >> k;
   
    for (int i = 0; i < k; i++) {

        int x, y;
        cin >> x >> y;
        value[x][y] = -1;
        value[y][x] = 1; 
        //value 라는 값에 선후 관계를 넣어준다.

    }

    cin >> s;
    
    for(int i=0;i<s;i++){
        int start, end;
        cin >> start >> end;
        a.push_back(make_pair(start, end));
        
    }
    
 for (int i = 1; i <= n; i++) { //플로와샬 알고리즘 진행
        for (int j = 1; j <= n; j++) {
            for (int z = 1; z <= n; z++) {
                if (!value[j][z] ) {
                    if(value[j][i]>0&&value[i][z]>0){
                        //같은 방향 즉,모든 경로를 탐색하는 것이 아니라 (역행) 선뱡항은 선뱡항 끼리 후 방향을 후방향 끼리 계산한다.
                        value[j][z] = value[j][i] + value[i][z];
                    }else if(value[j][i]<0&&value[i][z]<0){
                        value[j][z] = value[j][i] + value[i][z];
                    }
                  
                }

          }
    }
}



for (int test = 0; test < a.size(); test++) {

        int start = a[test].first;
        int end = a[test].second;

        cout << result_print(value[start][end]) << '\n';

    }
    return 0;
}