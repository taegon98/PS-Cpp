#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, less<ll>> pq;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    
    for (auto var : works) pq.push(var);
    
    while(n-- and pq.size()) {
        int n = pq.top();
        pq.pop();
        
        if (!n) continue;
        pq.push(--n);
    } 
    
    while(pq.size()) {
        answer += (pq.top() * pq.top());
        pq.pop();
    }
    
    return answer;
}