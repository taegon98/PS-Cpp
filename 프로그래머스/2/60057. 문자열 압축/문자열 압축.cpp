#include <string>
#include <vector>
using namespace std;

string go(int n, string s) {
    string ret = "", s1 = s.substr(0, n), s2 = "";
    int cnt = 1, i = n;

    for (;i < s.size() - n; i += n) {
        s2 = s.substr(i, n);

        if (s1 == s2) cnt++;
        else {
            if (cnt == 1) ret += s1;
            else ret += (to_string(cnt) + s1);
            s1 = s2;
            cnt = 1;
        }
    }
    s2 = s.substr(i);
    
    if (s1 == s2) {
        ret += (to_string(cnt + 1) + s1);
    }
    else {
        if (cnt > 1) ret += (to_string(cnt) + s1 + s2);
        else ret += (s1 + s2);
    }

    return ret;
}

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i < s.size() / 2 + 1; i++) {
        string temp = go(i, s);
        if (temp.size() < answer) answer = temp.size();
    }
    return answer;
}