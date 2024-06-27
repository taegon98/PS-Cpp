function solution(emergency) {
    var answer = [];
    let arr = [];
    let map = new Map();
    let order = 1;
    
    emergency.forEach((v) => arr.push(v));
    
    arr.sort((a, b) => {
        if (a < b) return 1;
        else if (a > b) return -1;
        else return 0;
    });
    
    for (let e of arr) {
        map.set(e, order++);
    }
    
    for (let e of emergency) {
        answer.push(map.get(e));
    }
    
    return answer;
}