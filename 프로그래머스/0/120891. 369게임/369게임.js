function solution(order) {
    let answer = Array.from(String(order)).filter(v => {
        if (v == 3 || v == 6 || v == 9) return true;
    }).length;
    return answer;
}