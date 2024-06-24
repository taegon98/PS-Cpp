function solution(numbers) {
    var answer = 0;
    
    for (let e of numbers) {
        answer += e;
    }
    
    return answer / numbers.length;
}