


let search_al = '';
let order = [];
let total = [];
let ans = [];
let max_num = [];

for (var i = 1; i < 15; i++) {
    total.push([]);
}

function go(count, limit, str, start, or) {
    if (count === limit) {
        let include = 0;
        for (let i = 0; i < order.length; i++) {
            let result = true;
            for (let k = 0; k < str.length; k++) {
                if (!order[i].includes(str[k])) {
                    result = false;
                    break;
                }
            }

            if (result) {
                include += 1;
            }

        }
        if (include > 1) {
            total[limit].push([str, include]);
            max_num[or] = Math.max(max_num[or], include);

        }
        return;
    }

    for (var i = start; i < search_al.length; i++) {
        if (str.indexOf(search_al[i]) == -1) {
            go(count + 1, limit, str + search_al[i], i + 1, or);
        }

    }


}


function solution(orders, course) {
    var answer = [];

    for (var i = 0; i < orders.length; i++) {
        order.push(orders[i].split('').sort().join(''));
        for (var j = 0; j < orders[i].length; j++) {
            if (search_al.includes(orders[i][j])) {
                continue;
            } else {
                search_al += orders[i][j];
            }

        }
    }

    search_al = search_al.split('').sort().join('')

    for (var i = 0; i < course.length; i++) {
        max_num.push(0);
        go(0, course[i], '', 0, i);
    }

    for (var i = 0; i < course.length; i++) {
        if (max_num[i]) {
            for (var j = 0; j < total[course[i]].length; j++) {
                if (total[course[i]][j][1] == max_num[i]) {
                    answer.push(total[course[i]][j][0]);
                }
            }

        }
    }
    answer.sort();


    return answer;
}