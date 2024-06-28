function solution(score) {
    var answer = [];
    let map = new Map();
    
    let arr = score.map((v) => v[0] + v[1]);
    let temp = arr.map(v => v);
    
    arr.sort((a, b) => {
        if (a < b) return 1;
        else if (a > b) return -1;
        else return 0;
    });
    
    arr.forEach((v, idx) => {
        if (!map.has(v)) map.set(v, idx + 1);
    });
    
    answer = temp.map((v) => map.get(v));
    
    return answer;
}