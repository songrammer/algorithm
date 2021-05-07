https://programmers.co.kr/learn/courses/30/lessons/42888

### 문제 설명

- 문제가 길기에 들어가서 확인 하시길!

### 문제 풀이

- 최종 출력 결과는 닉네임이 바뀐 결과로 출력해야한다.
- 따라서 닉네임을 map형태로 저장하고 난 뒤, record의 순서에 따라 출력한다.
- 닉네임 바뀔 경우
  - 들어온 상태에서 'Change'사용할 경우
  - 나간 상태에서 바뀐 채로 'Enter'할 경우

1. records에서 'Enter'과 'Change'를 탐색한다.
   - 'Enter'과 'Change'일 경우 객체에 key, value형태로 저장한다.
2. records에서 'Enter'과 'Leave'를 탐색한다.
   - map에서 해당하는 key의 value를 찾고 명령에 맞춰 메시지를 완성해 push한다.
