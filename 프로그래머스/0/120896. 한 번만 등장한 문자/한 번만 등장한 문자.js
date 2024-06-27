function solution(s) {
    var answer = '';
    let map = new Map();
    
    Array.from(s).forEach((v) => {
        if (map.has(v)) {
            map.set(v, map.get(v) + 1);
        } else {
            map.set(v, 1);
        }
    });
    
    for (let e of map.keys()) {
        if (map.get(e) === 1) answer += e;
    }    
    
    answer = Array.from(answer).sort().join("");
    
    return answer;
}