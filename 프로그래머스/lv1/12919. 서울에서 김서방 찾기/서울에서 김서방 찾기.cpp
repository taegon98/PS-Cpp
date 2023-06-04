#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int idx = 0;
    for (auto var : seoul) {
        if (var == "Kim") {
            string s = to_string(idx);
            answer += s;
            answer += "에 있다";
        }
        idx++;
    }
    return answer;
}