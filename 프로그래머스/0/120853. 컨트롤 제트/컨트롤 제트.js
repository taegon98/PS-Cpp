function solution(s) {
    var answer = 0;
    let arr = s.split(" ");
    let calc = [];
    
    arr.forEach((v) => {
        if (v !== 'Z') calc.push(v);
        else if (v === 'Z') calc.pop();
    });
    
    calc.forEach(v => answer += Number(v));
    
    return answer;
}