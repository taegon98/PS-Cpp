function solution(A, B) {
    var answer = 0;
    let arrA = Array.from(A);
    let cnt = 0;
    
    for (let i = 0; i < A.length; i++) {
        if (arrA.join("") === B) return cnt;
        arrA.unshift(arrA.pop());
        cnt++; 
    }
    
    return -1;
}