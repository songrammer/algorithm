https://www.acmicpc.net/problem/1753

### 문제 풀이

- 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000)
- 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정
- u에서 v로 가는 가중치 w인 간선이 있다.단 모든 간선의 가중치는 10 이하이다.
- 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.
- 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오.

#### 순서

- ~~다익스트라 힙 구조를 사용하려했으니 지점 끼리의 간선이 여러개 이기때문에 다른 방법을 고안한다~~
- 다익스트라 알고리즘은 음이 아닌 가중치가 있는 그래프에서 최단 경로를 찾는 가장 기본적이고 효율적인 알고리즘
- ~~다익스트라를 사용해도 괜찮다 **최단경로를**구하는 문제이기때문에, 간선이 여러개 있으면 제일 작은 값으로 저장한다.~~
  - 인접리스트로 규현하기에 여러 개 있는데로 그냥 진행하면 된다.
- 참고로 간선은 양방향이 아니다.
- ~~따라서 최종적으로 선형탐색을 이용한 다익스트라로 진행하면 O(v^2)이된다.~~
- V가 20,000이면 인접행렬은 4억이고 정수형이니 각 크기가 4B면 1600 MB임으로 인접행렬로 풀면 안된다.
- 따라서, 인접리스트인 우선순위 큐를 사용해서 풀어야한다. 시간복잡도는 O(V\*logV)이다.
  - 파이썬은 우선순위 큐(최소 힙) 으로 이루어 져 있다. 추가로 가중치를 기준으로 큐를 만들어야한다.

다익스트라 알고리즘 실수 정리 링크 :http://www.secmem.org/blog/2019/01/09/wrong-dijkstra/
