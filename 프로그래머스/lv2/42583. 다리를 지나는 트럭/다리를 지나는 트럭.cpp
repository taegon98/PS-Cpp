#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
deque<pair<int, int>> dq;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, idx = 0, cnt = 0;
    
    while(1) {
        for (int i = 0; i < dq.size(); i++) dq[i].first += 1;
        while(dq.size()) {
            if (dq.front().first == bridge_length) {
                weight += dq.front().second;
                cnt++;
                dq.pop_front();
            }
            else break;
        }
        
        if (weight >= truck_weights[idx]) {
            dq.push_back({0, truck_weights[idx]});
            weight -= truck_weights[idx++];
        }           

        answer++;
        if (cnt == truck_weights.size()) break;
    }
    return answer;
}