function solution(my_string, letter) {
    let answer;
    let my_string_arr = Array.from(my_string);
    answer = my_string_arr.filter(v => v != letter).join("");
    return answer;
}