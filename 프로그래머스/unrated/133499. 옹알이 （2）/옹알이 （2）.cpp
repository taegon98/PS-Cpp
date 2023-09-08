#include <string>
#include <vector>
using namespace std;
string str[] = {"aya", "ye", "woo", "ma"};

int check(string s) {
    int tot = 0;
    
    for (int i = 0; i < 4; i++) {
        auto pos = s.find(str[i]);
        string temp = s;
        int cnt = 0;
        
        while (pos != string::npos) {   
            temp = temp.erase(0, pos + str[i].size());
            pos = temp.find(str[i]);
            cnt += str[i].size();
            if (pos == 0) return 0;
        }
        tot += cnt;
    }
    return tot;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); i++) {
        if (check(babbling[i]) == babbling[i].size()) answer++;
    }
    
    return answer;
}