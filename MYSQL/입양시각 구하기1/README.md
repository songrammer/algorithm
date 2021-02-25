<<<<<<< HEAD
https://programmers.co.kr/learn/courses/30/lessons/59412
=======
https://programmers.co.kr/learn/courses/30/lessons/59406
>>>>>>> f3e18ff9bf6bfaa40f2157bcdffb5f52633be96b
#### 문제 설명
- ANIMAL_OUTS 테이블은 동물 보호소에 들어온 동물의 정보를 담은 테이블입니다. 
- ANIMAL_OUTS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, INTAKE_CONDITION, NAME, SEX_UPON_INTAKE는 각각 동물의 아이디, 생물 종, 보호 시작일, 보호 시작 시 상태, 이름, 성별 및 중성화 여부를 나타냅니다.
- <img src="./animalIn.png" width="500" height="300"/>
- 09:00부터 19:59까지, 각 시간대 별로 입양이 몇 건이나 발생했는 지 조회하시오
- 결과는 시간대 순으로 정렬해야합니다.

#### 문제 풀이
<<<<<<< HEAD
1. TYPE이 DATETIME 인 데이터에서 시간만 추출하려면 HOUR을 사용해야한다.
2. GROUP BY 를 진행 할시에 조건 추가는 HAVING을 이용한다.
3. ORDER BY로 순서를 오름 차순으로 한다.
=======
1.TYPE이 DATETIME 인 데이터에서 시간만 추출하려면 HOUR을 사용해야한다.
2.GROUP BY 를 진행 할시에 조건 추가는 HAVING을 이용한다.
3.ORDER BY로 순서를 오름 차순으로 한다.
>>>>>>> f3e18ff9bf6bfaa40f2157bcdffb5f52633be96b


