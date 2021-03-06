https://www.acmicpc.net/problem/1700

### 문제 설명
- 멀티탭 구멍의 개수 N (1 ≤ N ≤ 100)과 전기 용품의 총 사용횟수 K (1 ≤ K ≤ 100)가 정수로 주어진다. 
- 준규는 한 개의 멀티탭을 이용하고 있다.
- 여러 개의 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다
- 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.

 >   1.키보드
 >   2.헤어드라이기
 >   3.핸드폰 충전기
 >  4.디지털 카메라 충전기
 >  5.키보드
 >  6.헤어드라이기

 - 키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰충전기 플러그를 빼는 것이 최적일 것이므로 플러그는 한 번만 빼면 된다. 

- 하나씩 플러그를 빼는 최소의 횟수를 출력하시오. 


### 풀이
- devices [전기용품] :Bool으로 사용중인지 저장
- vector <int> order[전기용품]: 전기용품 별 순서 저장
- go [] :전체 순서 저장
- 전체 순서대로 탐색한다. 해당 하는 순서에 사용 중일 pop_back후 경우 넘어간다.
- 사용해야할 경우, 콘센트가 비어있으면 사용중으로 수정, 비어있지 않다면 탐색하여 **가장 뒤에 쓰일 가전제품 or 더 이상 사용되지 않을 가전 제품** 을 뺀다.

### 순서
1.  vector <int> order[]로 순서 저장 후 모두 각 가전제품의 순서를 내림차순으로 정렬한다.(쉽게 빼기 위해서)
2. 전체 순서대로 탐색한다.
    - 해당 순서에 이미 꽂혀있을 경우 vector <int> order[전기용품] 순서를 pop_back해준다.
         - **pop_back을 해주지 않아서 틀렸다.**
    - 꽂혀 있지 않을 경우, 콘센트가 비여있으면 사용중으로 수정 후 pop_back, 비어있지 않다면 3 을 진행한다.
3. 비어있지 않을 경우  vector <int> order[]를 전체 탐색하여 **가장 뒤에 쓰일것 이나** 쓰이지 않을  전기 용품 숫자를 알아낸다.
4. 해당 전기용품을 빼고 현재 순서의 전기용품을 꼽아준다.
    - order[전기용품] 순서를 pop_back ,devices[전기용품]=false, devices[현재순서]=true ,ans++ 



