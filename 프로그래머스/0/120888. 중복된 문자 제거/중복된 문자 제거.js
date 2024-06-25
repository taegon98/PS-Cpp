function solution(my_string) {
    let answer = "";
    Array.from(my_string).map(v => {
        if (!answer.includes(v)) answer += v;
    });
    return answer;
}