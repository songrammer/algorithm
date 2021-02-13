//코드 출처 https://seokeeee.tistory.com/124
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 25;
 
char what;
int n, m, map[MAX][MAX], dist[MAX][MAX];
 
const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };
 
// (r, c)부터 시작해서 일반적인 BFS를 통해 각 좌표까지의
// 거리의 최솟값을 dist 배열에 저장해주는 함수
void do_bfs(int r, int c) {
 
    bool check[MAX][MAX] = { 0, };
    queue <pair<int, int>> q;
 
    check[r][c] = true;
    q.push(make_pair(r, c));
 
    while (!q.empty()) {
        int rr = q.front().first, cc = q.front().second;
        q.pop();
 
        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nr = rr + dr[i], nc = cc + dc[i];
 
            // 다음칸이 배열을 벗어났거나, 가구(-1)이거나 이미 방문했으면
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (map[nr][nc] == -1 || check[nr][nc]) continue;
 
            // 위 if문에 걸리지 않았다면 무조건 방문하고 push, 
            // dist 배열에 거리까지 update 합니다
            check[nr][nc] = true;
            q.push(make_pair(nr, nc));
            dist[nr][nc] = dist[rr][cc] + 1;
        }
    }
}
 
int main(void) {
    while (1) {
        scanf("%d%d", &m, &n);         // [1]
        if (!n && !m) break;           // 입력받은 값이 둘 다 0이면 break
        
        memset(map, 0, sizeof(map));   // map 초기화
        vector <pair<int, int>> v(1);  // bfs 시작 좌표를 저장할 벡터
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &what);
                if (what == '*') {
                    // [1] 더러운 칸이라면 벡터의 맨 뒤에 넣고
                    v.push_back(make_pair(i, j));
                }
                else if (what == 'x') {
                    // 지나갈 수 없는 가구가 있는 칸이면 map에 -1을
                    map[i][j] = -1;
                }
                else if (what == 'o') {
                    // [1] 벡터의 맨 앞에는 로봇 청소기의 좌표를 넣어줍니다
                    v[0] = make_pair(i, j);
                }
            }
        }
 
        // [2] v 벡터의 처음부터 끝까지 모든 좌표에 대해
        int result[MAX][MAX] = { 0, };
        for (int i = 0; i < v.size(); i++) {
            
            // [2] dist 배열 초기화 후 bfs를 계속 진행합니다
            memset(dist, 0, sizeof(dist));
            do_bfs(v[i].first, v[i].second);
 
            for (int j = 0; j < v.size(); j++) {
 
                // [3] bfs가 끝나면 dist에 담긴 거리 정보를
                //     result 배열에 저장합니다
                result[i][j] = dist[v[j].first][v[j].second];
                // i번 좌표에서 j번 좌표로 가는 최단 거리
            }
        }
 
        // [4] 로봇 청소기의 인덱스를 빼고 저장합니다
        vector <int> location(v.size() - 1);
        for (int i = 0; i < v.size() - 1; i++)
            location[i] = i + 1;
 
        int ans = 987987987;
        bool flag = true;
 
        // [5]
        do {
            // 0번(로봇 청소기) -> 1번 거리
            int cur = result[0][location[0]];
            if (!cur) {
                // 로봇 청소기가 어떤 더러운 칸으로 가는 거리가
                // 하나라도 0 이라면 바로 탈출
                flag = false;
                break;
            }
            // 1번 -> 2번 거리, 2번 -> 3번 거리, ... 를 다 더해줍니다
            for (int i = 0; i < v.size() - 2; i++) {
                cur += result[location[i]][location[i + 1]];
            }
            if (ans > cur) ans = cur;
        } while (next_permutation(location.begin(), location.end()));
 
        if (!flag) printf("-1\n"); // 불가능한 경우
        else printf("%d\n", ans);
    }
    return 0;
}