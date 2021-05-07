function solution(s) {

    let result;

    result = 0;
    let temp = [];

    for (var i = 0; i < s.length; i++) {


        if (!temp.length) {
            temp.push(s[i]);
        } else {
            let last = temp[temp.length - 1];
            let cur = s[i];
            if (last === cur) {
                temp.pop();
            } else {
                temp.push(cur);
            }

        }

    }


    return temp.length ? 0 : 1;
}