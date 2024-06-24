function gcd(a, b) {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}

function solution(n) {
    let answer = 6 * n / gcd(6, n) / 6;
    return answer;
}