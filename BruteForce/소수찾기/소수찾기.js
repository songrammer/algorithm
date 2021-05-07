


function solution(numbers) {

    let visited = [0, 0, 0, 0, 0, 0, 0, 0];
    let made = [];


    function check_sosu(num) {

        if (num == 1 || num[0] == '0') {
            //1이나 문자가 0으로 시작할 경우('011') 걸러줌
            return false;
        }
        for (var i = 2; i <= Math.sqrt(num); i++) {
            //아리스토체 방식 소수 체킹
            if (num % i == 0) {
                return false;
            }
        }
        return true;

    }


    function go(cnt, indx, numbers, num) {

        if (cnt && check_sosu(num) && !made.includes(num)) {
            // 아예 아무것도 안 만들어 진 상황 부터 시작하기때문에 cnt=1이상일때 부터 확인해준다.

            made.push(num);
            //소수이고 같은 숫자가 만들어진 적없으면 추가
        }

        if (cnt == numbers.length) {
            //최대 numbers길이 넘어가지 않게 종료
            return;
        }

        for (var i = 0; i < numbers.length; i++) {
            if (visited[i]) continue;
            visited[i] = 1;
            go(cnt + 1, i, numbers, num + numbers[i]);
            visited[i] = 0;
        }
    }


    go(0, 0, numbers, '');
    return made.length;
}