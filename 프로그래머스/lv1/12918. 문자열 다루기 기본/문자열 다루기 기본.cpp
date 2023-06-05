#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.size() != 4 and s.size() != 6) answer = false;
    else {
        for (auto var : s) {
            if (isalpha(var)) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}