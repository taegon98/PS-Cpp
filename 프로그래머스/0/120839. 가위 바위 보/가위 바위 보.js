function solution(rsp) {
    let answer = "";
    
    for (let e of rsp) {
        if (e === '2') answer += '0';
        else if (e === '0') answer += '5';
        else answer += '2';
    }
    return answer;
}