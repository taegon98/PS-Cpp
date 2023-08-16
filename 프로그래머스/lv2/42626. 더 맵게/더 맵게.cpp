#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for (auto var : scoville) pq.push(var);
    
    while(1) {
        if (pq.top() >= K) break;
        else if (pq.size() <= 1) {
            answer = -1;
            break;
        }
        else answer++;
        
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + (b * 2);
        
        pq.push(c);
    }
    
    return answer;
}