https://programmers.co.kr/learn/courses/30/lessons/59047
#### 문제 설명
- ANIMAL_INS 테이블은 동물 보호소에 들어온 동물의 정보를 담은 테이블입니다. 
- ANIMAL_INS 테이블 구조는 다음과 같으며, ANIMAL_ID, ANIMAL_TYPE, DATETIME, INTAKE_CONDITION, NAME, SEX_UPON_INTAKE는 각각 동물의 아이디, 생물 종, 보호 시작일, 보호 시작 시 상태, 이름, 성별 및 중성화 여부를 나타냅니다.
- <img src="./animalIn.png" width="500" height="300"/>
- 보호소에 있는 이름중 이름에 EL이 들어가는 개의 아이디와 이름을 조회 하는 SQL문을 작성하시오.
- 결과는 이름 순이며, 대소문자는 구분하지 않는다.

#### 문제 풀이
1. LIKE는 특정 문자열 포함 여부를 확인한다.'a%'면 a로 시작하는 ~~인 경우를 찾는다. 해당 경우는 앞뒤 상관 없이 포함이므로 '%a%'를 사용해야한다.
2. 조건이 (WHERE) ANIMAL_TYPE='Dog' 과 (AND) NAME LIKE '%el%'을 이용한다.



