#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int alpha[30];

vector<int> solution(string s) {
    vector<int> answer;
    fill(alpha, alpha + 30, -1);
    for (int i = 0; i < s.size(); i++) {
        if (alpha[s[i] - 'a'] == -1) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(i - alpha[s[i] - 'a']);
        }
        alpha[s[i] - 'a'] = i;
    }
    return answer;
}