SET @hour := -1; -- 대입 연산 변수 와 초깃 값

SELECT (@hour := @hour + 1) as HOUR, --누적하여 -1부터 1 씩 증가한다
(SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @hour) as COUNT --같은거 숫자 세기
FROM ANIMAL_OUTS
WHERE @hour < 23