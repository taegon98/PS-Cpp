function solution(my_str, n) {
    var answer = [];
    while(my_str.length) {
        answer.push(my_str.slice(0,n));
        my_str = my_str.slice(n);
    }
    return answer;
}