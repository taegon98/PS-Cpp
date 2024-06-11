#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int r, c;
map<string, int> mp;
vector<pair<vector<int>, bool>> v;
bool isPrimary = true;

void go(int depth, int idx, vector<int> pos) {
    if (pos.size() == depth) {
        v.push_back({pos, true});
        return;
    }
    
    for (int i = idx; i < c; i++) {
        pos.push_back(i);
        go(depth, i + 1, pos);
        pos.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    r = relation.size();
    c = relation[0].size();
    
    for (int i = 1; i <= c; i++) {
        go(i, 0, vector<int>());
    }
    
    for (auto var : v) {   
        if (!var.second) continue;
        bool flag = true;
        map<string, int> temp;
        for (int i = 0; i < r; i++) {
            string s = "";
            
            for (auto idx : var.first) {
                s += relation[i][idx];
            }
            
            if (temp[s]) {
                flag = false;
                break;
            }
            
            temp[s] = 1;
        }
        
        if (flag) {
            for (int i = 0; i < v.size(); i++) {
                int cnt = 0;
                for (int j = 0; j < v[i].first.size(); j++) {
                    for (auto idx : var.first) {
                        if (idx == v[i].first[j]) cnt++;
                    }
                    if (cnt >= var.first.size()) {
                        v[i].second = false;
                    }
                }
            }
            answer++;
        }
    }
    return answer;
}