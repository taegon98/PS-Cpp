#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> mp;

int to_days(string date) {
    int tot_days = 0;
    
    tot_days += (stoi(date.substr(0, 4)) * 12 * 28);
    tot_days += (stoi(date.substr(5, 2)) * 28);
    tot_days += stoi(date.substr(8, 2));
    
    return tot_days;
}

vector<int> getExp(vector<string> p) {
    vector<int> v;
    
    for (auto var : p) {
        char type = var.back();
        int days = mp[type] * 28 - 1;
        days += to_days(var.substr(0, var.size() - 2));
        v.push_back(days);
    }
    
    return v;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> exp;
    
    for (auto var : terms) {
        mp[var[0]] = stoi(var.substr(2));
    }
    
    int cur = to_days(today);
    exp = getExp(privacies);
    
    for (int i = 0; i < exp.size(); i++) {
        if (cur > exp[i]) answer.push_back(i + 1);
    }
    return answer;
}