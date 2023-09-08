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
        s.push(number[i]);
        if (!ok) break;
    }
    i++;
    
    while(s.size()) {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    
    if (i < number.size()) 
        answer += (number.substr(i));
    
    while (cnt < k) {
        answer.pop_back();
        cnt++;
    }
   
    return answer;
}