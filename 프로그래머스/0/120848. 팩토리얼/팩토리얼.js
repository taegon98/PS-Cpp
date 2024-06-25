function factorial(n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

function solution(n) {
    let num = 1;
    while(1) {
        if (factorial(num) > n) break;
        answer = num++;
    }
    return answer;
}