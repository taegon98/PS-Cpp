#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> mp, check, info;
vector<int> answer;
vector<string> v[1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    int idx = 0;
    for (auto var : id_list) {
        mp[var] = 0;
        info[var] = idx++;
    }
    
    for (auto var : report) {
        if (check.find(var) != check.end()) continue;
        else check[var]++;
        
        int index = var.find(" ");
        string s = var.substr(0, index);
        var.erase(0, index + 1);
        
        mp[var]++;
        v[info[s]].push_back(var);
    }
    
    for (int i = 0; i < idx; i++) {
        int cnt = 0;
        for (int j = 0; j < v[i].size(); j++) {
            if (mp[v[i][j]] >= k) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}