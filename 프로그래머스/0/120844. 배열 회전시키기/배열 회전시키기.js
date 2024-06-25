function solution(numbers, direction) {
    var answer = [];
    if (direction === "right") {
        answer.push(numbers[numbers.length - 1]);
        for (let e = 0; e < numbers.length - 1; e++) {
            answer.push(numbers[e]);
        }
    } else if (direction === "left") {
        for (let e = 1; e < numbers.length; e++) {
            answer.push(numbers[e]);
        }
        answer.push(numbers[0]);
    }
    return answer;
}