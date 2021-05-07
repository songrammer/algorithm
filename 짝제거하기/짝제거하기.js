function solution(s) {

    let result;
    while (s.length) {
        result = 0;
        let temp = '';

        for (var i = 0; i < s.length - 1; i++) {
            if (s[i] === s[i + 1]) {
                i += 1;
                result = 1;
            } else {
                temp += s[i];
            }
        }

        if (!result) {
            break;
        }

        s = temp;
    }

    return result;
}