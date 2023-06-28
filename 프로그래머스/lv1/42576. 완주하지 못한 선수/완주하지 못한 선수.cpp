#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mp;
    for (auto var : participant) {
        mp[var]++;
    }
    for (auto var : completion) {
        mp[var]--;
    }
    for (auto iter = mp.begin() ; iter != mp.end(); iter++) {
        if (iter->second != 0) answer = answer + (iter->first);
    }
    return answer;
}