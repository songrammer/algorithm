### 문제 풀이
- 2 ≦ n, m ≦ 30
- 판 정보를 가지고 지워지는 최종 블록의 갯수를 구하여라
- 게임판에 2×2 형태로 같은 모양이 붙어있으면 지워지고 지워지는 공간은 위에 블록이 아래로 떨어진다.
- 빈 공간을 채운 후에 다시 2×2 형태로 같은 모양의 블록이 모이면 다시 지워지고 떨어지고를 반복하게 된다.


#### 순서
1. 문자열 리스트 형태로 모두 변환(인덱스로 접근이 가능하게)
2. 무한 반복분을 통해 2×2 형태로 같은 모양이 붙어있으면 계속 게임 진행
3. 2×2 형태로 같은 모양이 붙어있으면 시작점 저장
4. 저장된 시작점을 대상으로 모양을 비어있게 (본인은 '0'으로) 문자 수정
5. 무한 반복문을 통해 해당 좌표는 문자 이지만 바로 아래 비어있으면 이면 아래로 이동(만일 이동할게 없으면 종료)
6. 최종 비어있는 문자 횟수 카운팅 


