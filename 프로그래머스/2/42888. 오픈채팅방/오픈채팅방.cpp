#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> isName;
map<string, int> isExist;
vector<string> answer;

vector<string> split(string s) {
    char delimiter = ' ';
    vector<string> v;
    int idx;
    
    while((idx = s.find(delimiter)) != -1) {
        v.push_back(s.substr(0, idx));
        s = s.substr(idx + 1);
    }
    v.push_back(s);
    
    return v;
}


vector<string> solution(vector<string> record) {
    for (int i = 0; i < record.size(); i++) {
        vector<string> temp = split(record[i]);
        if (temp[0] == "Enter") {
            if (isExist[temp[1]]) {
                isName[temp[1]] = temp[2];
            }
            else {
                isExist[temp[1]] = 1;
            }
            
            isName[temp[1]] = temp[2];
            string s = temp[1] + "님이 들어왔습니다.";
            answer.push_back(s);
        }
        else if (temp[0] == "Leave") {
            string s = temp[1] + "님이 나갔습니다.";
            answer.push_back(s);
        }
        else if(temp[0] == "Change") {
            isName[temp[1]] = temp[2];
        }
    }
    
    for (int i = 0; i < answer.size(); i++) {
        int idx = answer[i].find("님");
        string s = isName[answer[i].substr(0, idx)] + answer[i].substr(idx);
        answer[i] = s;
    }
    return answer;
}