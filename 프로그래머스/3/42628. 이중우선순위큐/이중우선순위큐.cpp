#include <string>
#include <vector>
#include <queue>
#include <map>
#define INF 987654321
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;
map<int, int> mp;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for (auto var: operations) {
        if (var[0] == 'I') {
            int num = stoi(var.substr(2));
            mp[num]++;
            min_heap.push(num);
            max_heap.push(num);
        } else if(var == "D -1") {
            while(min_heap.size()) {
                int num = min_heap.top();
                if (mp[num]) {
                    mp[num]--;
                    min_heap.pop();
                    break;
                } else {
                    min_heap.pop();
                }
            }
        } else {
            while(max_heap.size()) {
                int num = max_heap.top();
                if (mp[num]) {
                    mp[num]--;
                    max_heap.pop();
                    break;
                } else {
                    max_heap.pop();
                }
            }
        }
    }
    
    int max_val = -INF;
    int min_val = INF;
    for (auto var : mp) {
        if (var.second != 0) {
            max_val = max(max_val, var.first);
            min_val = min(min_val, var.first);
        }
    }
    
    if (max_val == -INF and min_val == INF) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(max_val);
        answer.push_back(min_val);
    }
    
    return answer;
}