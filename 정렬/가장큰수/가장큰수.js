function solution(numbers) {
    var answer = '';
    var arr = [];

    for (let i = 0; i < numbers.length; i++) {
        arr.push(String(numbers[i]));
    }
    arr.sort(function (a, b) {
        return (b + a) - (a + b);
    });

    if (arr[0] === '0') {
        return '0';
    }

    for (let i = 0; i < numbers.length; i++) {
        answer += arr[i];
    }


    return answer;
}