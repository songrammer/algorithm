function solution(n, edge) {
    var answer = 0;
    const graph = {};
    let max_len = 0;


    input();
    BFS(graph, 1);

    function input() {

        //객체로 인접리스트 만들기
        edge.forEach((v) => {
            graph[v[0]] = (graph[v[0]] || []).concat(v[1]);
            graph[v[1]] = (graph[v[1]] || []).concat(v[0]);

        });

    }


    function BFS(graph, node) {
        //BFS
        let visited = [];
        let queue = [];
        let dist = 0;

        queue.push([node, dist]);
        visited.push(node);

        while (queue.length !== 0) {

            [node, dist] = queue.shift();
            graph[node].forEach((next) => {
                if (!visited.includes(next)) {
                    if (max_len < dist) {
                        //최대 일때 갱신
                        max_len = dist;
                        answer = 0;
                    }
                    if (max_len === dist) {
                        //최댓값과 같을 때 카운팅
                        answer += 1;
                    }
                    visited.push(next);
                    queue.push([next, dist + 1]);
                }
            })


        }

    }



    return answer;
}