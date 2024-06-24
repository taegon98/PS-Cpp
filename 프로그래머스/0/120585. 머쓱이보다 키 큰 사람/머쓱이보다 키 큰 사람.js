function solution(array, height) {
    let answer = 0;
    
    for (let e of array) {
        if (e > height) answer++;
    }
    return answer;
}