function check(i, k) {
    let str = String(i);
    let cnt = 0;
    for (let e of str) {
        if (e == k) cnt++;
    }
    return cnt;
}

function solution(i, j, k) {
    var answer = 0;
    
    for (let e = i; e <= j; e++) {
        answer += check(e, k);
    }
    return answer;
}