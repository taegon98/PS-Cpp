function solution(array, n) {
    let answer;
    let diff = 987654321;
    
    array.sort((a, b) => {
        if (a > b) return 1;
        else if (a < b) return -1;
        else return 0;
    });
    
    array.forEach(v => {
        if (Math.abs(n - v) < diff) {
            diff = Math.abs(n - v);
            answer = v;
        }
    });
    return answer;
}