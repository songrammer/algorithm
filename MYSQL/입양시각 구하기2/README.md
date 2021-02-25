https://programmers.co.kr/learn/courses/30/lessons/59413
#### 문제 설명
- ANIMAL_OUTS 테이블은 동물 보호소에 들어온 동물의 정보를 담은 테이블입니다. 
- ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, INTAKE_CONDITION, NAME, SEX_UPON_INTAKE는 각각 동물의 아이디, 생물 종, 보호 시작일, 보호 시작 시 상태, 이름, 성별 및 중성화 여부를 나타냅니다.
- <img src="./animalIn.png" width="500" height="300"/>
-  0시부터 23시까지 각시간대 별로 입양이 몇건이나 발생했는지 결과문을 작성해주세요

#### 문제 풀이
https://chanhuiseok.github.io/posts/db-6/
1. SET 옆에 변수명과 초기값을 설정,이를 통해 값을 누적하여 0부터 23까지 표현
2. (@hour := @hour +1)  누적하여 증가시킴
3. WHERE @hour < 23일 때까지

