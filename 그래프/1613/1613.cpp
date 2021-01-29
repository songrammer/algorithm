#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 405
using namespace std;

int result_print(int num) { //결과 출력함수


if (num) {
    if (num > 0) {
            return 1;
    } else {
            return -1;
      }

    } else {
        return 0;
    }

}

int main() {
    
    int n, k, s;
    int value[MAX][MAX];
    cin >> n >> k;
    vector < int > v[MAX];

    memset(value, 0, sizeof(value));

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);

        value[x][y] = -1;
        value[y][x] = 1;
        //선후관계 저장

    }

    cin >> s;

    vector < pair < int, int > > a;
    
    while (s--) {
        int start, end;
        cin >> start >> end;
        a.push_back(make_pair(start, end));
    }


    for (int test = 0; test < a.size(); test++) {

        int start = a[test].first;
        int end = a[test].second;

        int visit[MAX];
        fill_n(visit,MAX,0);

        queue < int > q;
        q.push(start);
        visit[start]=0;
        int result = 0;

        while (!q.empty()) { //BFS 탐색

            int x = q.front();
            q.pop();

            if (x == end) { //해당하는 곳에 도착했을 시에, 종료 및 visited 값 저장

                result = visit[x];
                break;
            }

            for (int i = 0; i < v[x].size(); i++) {
                int y = v[x][i];

                if (visit[y]==0&&y!=start) {

                    q.push(y);
                    visit[y] = value[x][y]+visit[x];

                }

            }

        }

        cout << result_print(result) << '\n';

    }

    return 0;
}