#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int mid = s.size() / 2;
    bool flag = false;
    if (s.size() % 2 == 0) flag = true;
    
    if (flag) answer = s.substr(mid - 1, 2);
    else answer = s[mid];
    return answer;
}