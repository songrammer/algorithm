https://www.acmicpc.net/problem/16234

### 문제 설명

<img src="./img2.png" width="800" height="300">

- 첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)

- 둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)

- 인구 이동이 발생하는 횟수가 2,000번 보다 작거나 같은 입력만 주어진다.

---

### 풀이

- 연합을 찾는 문제다. 각 인접하는 지점의 국경의 문이 열리지 않더라도 다른 연결 점을 통해 한 연합이 될 수있다.

- 이는 DFS로 연합 group을 찾은 다음 (연합의 인구수) , (연합을 이루고 있는 칸의 개수)을 저장한다.

  > 이때, 연합의 수가 여러개 일 수도 있으니 vector에 연합이 발견 될 마다 push 한다.

- 연합을 모두 찾으면 , 연합의 포함되는 국가 인구수를 각자의 연합의 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)로 대체한다.

- 더 이상 연합이 안 만들어지면 종료한다.

---

### 순서

> vector<pair<int, int> > result_cnt :연합 별 넘버링과 (연합의 인구수) , (연합을 이루고 있는 칸의 개수) 배열

> int visited[55][55] :방문 여부 체킹과 연합 넘버링

1. 모든 국가를 탐색한다.

   - 해당 하는 좌표의 상하좌우 국가와의 인구수가 L이상 R이하 && 방문하지 않았으면 DFS탐색한다.

2. DFS 탐색하며 재귀적으로 연합을 찾는다.

   - 재귀적으로 (연합의 인구수) , (연합을 이루고 있는 칸의 개수)를 반환한다.

3. 탐색 후에 visited[][] 값이 -1이 아니라면 해당하는 국가의 인구 수를 연합의 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)로 대체한다.
