function has_3(num) {
    let str = String(num);
    
    for (let e of str) {
        if (e === '3') return true;
    }
    return false;
}

function solution(n) {
    let num = 1;
    
    for (let e = 1; e <= n; e++) {
        while(true) {
            if (num % 3 == 0 || has_3(num)) num++;
            else {
                num++; break;
            }
        }
    }
    return num - 1;
}