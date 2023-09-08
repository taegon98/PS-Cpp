#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<pair<int, int>> s;
int arr[1000001];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int max_val = -987654321;
    for (int i = 1; i <= numbers.size(); i++) {
        max_val = max(max_val, numbers[i - 1]);
        while (!s.empty() and s.top().first < numbers[i - 1]) {
            arr[s.top().second] = numbers[i - 1];
            s.pop();
        }
        s.push({numbers[i - 1], i});
    }
    
    while(s.size()) {
        arr[s.top().second] = -1;
        s.pop();
    }
    
    for (int i = 1; i <= numbers.size(); i++) {
        if (!arr[i]) continue;
        answer.push_back(arr[i]);
    }
    
    return answer;
}