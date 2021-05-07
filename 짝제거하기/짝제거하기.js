function solution(s) {

    let result;
    while (s.length) {
        result = 0;
        for (var i = 0; i < s.length - 1; i++) {
            if (s[i] === s[i + 1]) {
                s = s.slice(0, i) + s.slice(i + 2);
                result = 1;
                i = i - 1;

            }
        }
        if (!result) {
            break;
        }


    }

    return result;
}