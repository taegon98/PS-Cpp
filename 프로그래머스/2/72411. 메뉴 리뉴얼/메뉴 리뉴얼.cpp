#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> mp;

void go(string str, int depth, string cur, int idx) {
    
    if (cur.size() == depth) {
        sort(cur.begin(), cur.end());
        mp[cur]++;
        return;
    }
    
    for (int i = idx; i < str.size(); i++) {
        cur.push_back(str[i]);
        go(str, depth, cur, i + 1);
        cur.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (auto var : orders) {
        for (int i = 0; i < course.size(); i++) {
            go(var, course[i], "", 0);
        }
    }
    
    for (int i = 0; i < course.size(); i++) {
        int max_val = -987654321;
        vector<pair<string, int>> temp;
        
        for (auto var : mp) {
            if (var.second < 2) continue;
            if (var.first.size() == course[i] && var.second >= max_val) {
                temp.push_back({var.first, var.second});
                max_val = var.second;
            } 
        }
        
        for (auto var : temp) {
            if (max_val == var.second) answer.push_back(var.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}