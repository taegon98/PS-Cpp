#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, int> mp;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for (auto var : keymap) {
        for (int i = 0; i < var.size(); i++) {
            if (mp.find(var[i]) == mp.end()) mp[var[i]] = i + 1;
            if (mp[var[i]] > i + 1) mp[var[i]] = i + 1;
        }
    }
    
    for (auto var : targets) {
        int temp = 0;
        bool ok = true;
        for (int i = 0; i < var.size(); i++) {
            if (mp.find(var[i]) == mp.end()) {
                ok = false;
                break;
            }
            temp += mp[var[i]];
        }
        if (!ok) answer.push_back(-1);
        else answer.push_back(temp);
    }
    return answer;
}