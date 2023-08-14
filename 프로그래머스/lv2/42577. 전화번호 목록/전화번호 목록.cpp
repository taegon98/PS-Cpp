#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> mp;
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (auto var : phone_book) {
        mp[var] = 1;
    }
    
    for (auto var : phone_book) {
        for (int i = 0; i < var.size() - 1; i++) {
            if (mp.find(var.substr(0, i + 1)) != mp.end()) {
                answer = false; break;
            }
        }
        if (!answer) break;
    }
    
    return answer;
}