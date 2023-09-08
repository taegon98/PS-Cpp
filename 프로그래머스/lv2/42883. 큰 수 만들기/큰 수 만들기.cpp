#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0, i = 0;
    stack<int> s;
    
    for (; i < number.size(); i++) {
        bool ok = true;
        while (!s.empty() and s.top() < number[i]) {
            s.pop();
            cnt++;
            if (cnt == k) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
        s.push(number[i]); 
    }
    
    while(s.size()) {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    
    answer += (number.substr(i));
    
    while (cnt < k) {
        answer.pop_back();
        cnt++;
    }
   
    return answer;
}