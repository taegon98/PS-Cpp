#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int solution(int n, int k, vector<int> enemy) {
    int round = 0;
    int tot_round = enemy.size();
    
    for (; round < enemy.size(); round++) {
        if (k) {
            pq.push(enemy[round]);
            k--;
        }
        else {
            if (pq.top() < enemy[round]) {
                n -= pq.top();
                pq.pop();
                pq.push(enemy[round]);
            }
            else {
                n -= enemy[round];
            }
        }
        if (n < 0) break;
        if (n < tot_round - round);
    }
    
    return round;
}