function solution(s1, s2) {
    let answer = 0;
    for (let e1 of s1) {
        for (let e2 of s2) {
            if (e1 === e2) {
                answer++;
                break;
            }
        }
    }

    return answer;
}