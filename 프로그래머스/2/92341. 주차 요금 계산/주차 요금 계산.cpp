#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

map<string, string> mp;
map<int, int> answer;
vector<string> temp;

vector<string> split(string s1) {
    char delimiter = ' ';
    vector<string> temp;
    int idx;
    
    while ((idx = s1.find(delimiter)) != -1) {
        string s2 = s1.substr(0, idx);
        temp.push_back(s2);
        s1 = s1.substr(idx + 1);
    }
    temp.push_back(s1);
    
    return temp;
}

int calcDiff(string s) {
    int h = stoi(s.substr(0, 3)) * 60;
    int m = stoi(s.substr(3));
    return h + m;
}

int calcFees(int t, vector<int> fees) {  
    int tot = fees[1];
    t -= fees[0];
    
    if (t > 0) {
        int loop = ceil((double)t / (double)fees[2]);
        tot += (loop * fees[3]);
    }
    return tot;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> v;
    
    for (int i = 0; i < records.size(); i++) {
        temp = split(records[i]);
        
        if (temp[2] == "IN") {
            mp[temp[1]] = temp[0];
        }
        else if (temp[2] == "OUT") {
            int cur = calcDiff(temp[0]);
            int pre = calcDiff(mp[temp[1]]);
            int diff = cur - pre;
    
            answer[stoi(temp[1])] += diff;
            mp.erase(temp[1]);
        }
    }
    
    for (auto var : mp) {
        int cur = calcDiff("23:59");
        int pre = calcDiff(var.second);
        int diff = cur - pre;
        
        answer[stoi(var.first)] += diff;
    }
    
    for (auto var : answer) {
        v.push_back(calcFees(var.second, fees));
    }
    return v;
}