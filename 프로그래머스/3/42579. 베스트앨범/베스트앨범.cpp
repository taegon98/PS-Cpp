#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> mp1; //pri 1
map<string, vector<pair<int, int>>> mp2; //pri 2

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

bool compare(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int>> temp;
    
    for (int i = 0; i < genres.size(); i++) {
        mp1[genres[i]]+=plays[i];
        mp2[genres[i]].push_back({plays[i], i});
    }
    
    for (auto var : mp1) temp.push_back({var.first, var.second});
    sort(temp.begin(), temp.end(), compare);

    for (auto var : temp) {
        vector<pair<int, int>> v = mp2[var.first];
        sort(v.begin(), v.end(), cmp);
        
        answer.push_back(v[0].second);
        if (v.size() >= 2) {
            answer.push_back(v[1].second);
        }
    }
   
    return answer;
}