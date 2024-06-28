function solution(polynomial) {
    var answer = '';
    let arr = polynomial.split(" ");
    let m = 0;
    let n = 0;
    
    for (let e of arr) {
        if (e === "+") continue;
        if (e[e.length - 1] === 'x') {
            if (e.length > 1)
                m += Number(e.slice(0, e.length - 1));
            else
                m++;
        } else {
            n += Number(e);
        }
    }
    
    if (m === 1) answer += "x";
    else if (m > 1) answer += (m + "x");
    
    if (m === 0 && n !== 0) answer += n;
    else if (n !== 0) answer += (" + " + n);
    
    return answer;
}