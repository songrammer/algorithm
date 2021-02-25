https://programmers.co.kr/learn/courses/30/lessons/59406
#### 문제 설명
- ANIMAL_INS 테이블은 동물 보호소에 들어온 동물의 정보를 담은 테이블입니다. 
- ANIMAL_INS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, INTAKE_CONDITION, NAME, SEX_UPON_INTAKE는 각각 동물의 아이디, 생물 종, 보호 시작일, 보호 시작 시 상태, 이름, 성별 및 중성화 여부를 나타냅니다.
- <img src="./animalIn.png" width="500" height="300"/>
- 보호소에 있는 동물이 몇 마리 있는지 조회하는 SQL문을 작성하시오.

#### 문제 풀이
1.COUNT를 이용하여 숫자를 센다.
2.테이블에서 NULL이 FALSE인 컬럼하나를 선택해 COUNT한다.
3.별칭을 사용해서 count로 나타낸다.



