#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<pair<int, int>> s;
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    for (int i = 0; i < numbers.size(); i++) {
        while (!s.empty() and s.top().first < numbers[i]) {
            answer[s.top().second] = numbers[i];
            s.pop();
        }
        s.push({numbers[i], i});
    }
    
    return answer;
}