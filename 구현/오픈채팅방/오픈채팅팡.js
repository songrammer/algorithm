function solution(record) {
    var answer = [];
    let names = {};

    for (var i = 0; i < record.length; i++) {
        let arr = record[i].split(' ');
        if (arr[0] === 'Enter' || arr[0] === 'Change') {

            names[arr[1]] = arr[2];
        }
    }

    for (var i = 0; i < record.length; i++) {

        let arr = record[i].split(' ');
        let message = names[arr[1]] + '님이 ';
        let action = '';

        if (arr[0] === 'Enter') {
            action += '들어왔습니다.'
        } else if (arr[0] === 'Leave') {
            action += '나갔습니다.'
        } else {
            continue;
        }
        message += action;
        answer.push(message);

    }

    return answer;
}