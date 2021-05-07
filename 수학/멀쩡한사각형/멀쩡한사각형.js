
function solution(w, h) {

    function gcd(a, b) {
        let min = Math.min(a, b);
        let max = Math.max(a, b);

        if (min == 0) {
            return max;
        }

        return gcd(min, max % min);

    }


    return w * h - (w + h - gcd(w, h));
}