#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> v;
    int answer = 0;
    while(s.size()) {
        bool ok = false;
        char ch = s[0];
        int cnt_1 = 0, cnt_2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch) cnt_1++;
            else cnt_2++;
            
            if (cnt_1 == cnt_2) {
                v.push_back(s.substr(0, i + 1));
                answer++;
                s.erase(0, i + 1);
                ok = true;
                break;
            }
        }
        if (!ok) {
            answer++;
            break;
        }
    }
    return answer;
}