#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int gcd(int a, int b) {
    int temp;
    
    while(1) {
        if (b == 0) return a;
        else {
            temp = b;
            b = a % b;
            a = temp;
        }
    }
}
    

int solution(vector<int> arr) {
    int answer = 0;
    for (auto var : arr) pq.push(var);
    
    while(pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a * b / gcd(a, b);
        pq.push(c);
    }
    answer = pq.top();
    return answer;
}