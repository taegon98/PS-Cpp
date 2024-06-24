function solution(n, k) {
    let tot = 0;
    let service = 0;
    
    tot += (n * 12000);
    tot += (k * 2000);
    
    if (n >= 10) {
        service = Math.floor(n / 10);
        tot -= (service * 2000);
    }
    
    return tot;
}