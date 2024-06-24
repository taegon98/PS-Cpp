function solution(num_list) {
    var answer = [];
    answer.push(num_list.filter(v => (v % 2 === 0)).length);
    answer.push(num_list.filter(v => (v % 2 === 1)).length);
    return answer;
}