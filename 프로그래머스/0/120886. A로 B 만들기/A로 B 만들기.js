function solution(before, after) {
    let before_arr = Array.from(before).sort().join("");
    let after_arr = Array.from(after).sort().join("");
    if (before_arr === after_arr) return 1;
    else return 0;
}