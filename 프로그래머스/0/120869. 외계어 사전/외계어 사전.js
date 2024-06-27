function solution(spell, dic) {
    var answer = 0;
    
    for (let str of dic) {
        let arr = Array.from(str);
        let cnt = 0;
        
        for (let e of spell) {
            if (!arr.includes(e)) break;
            cnt++;
        }

        if (cnt === spell.length) {
            return 1;
        }
    }
    return 2;
}