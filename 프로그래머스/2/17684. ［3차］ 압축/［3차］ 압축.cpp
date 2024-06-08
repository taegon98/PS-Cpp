#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, int> mp;
int n = 27;

void init() {
    char alpha = 'A';
    
    for (int i = 1; i <= 26; i++) {
        string s(1, alpha);
        mp[s] = i;
        alpha++;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    init();
    
    while(msg.size()) {
        int temp = 0;
        int cur_idx = 0;
        string s = "";
        
        while(1) {
            s += msg[cur_idx];
            if (mp[s]) {
                temp = mp[s];
                cur_idx++;
            } else {
                answer.push_back(temp);
                mp[s] = n++;
                msg = msg.substr(cur_idx);
                break;
            }
            
            if (cur_idx >= msg.size()) {
                answer.push_back(temp);
                return answer;
            }
        }
    }
    
    return answer;
}