#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> mp1;
    map<int, string> mp2;
    
    for (int i = 0; i < players.size(); i++) {
        mp1[players[i]] = i;
        mp2[i] = players[i];
    }
    
    for (auto var : callings) {
        int temp = mp1[var];
        string str = mp2[temp - 1];
        
        mp1[var] -= 1;
        mp1[str] += 1;
        
        mp2[temp - 1] = var;
        mp2[temp] = str;
    }
    for (auto var : mp2) {
        answer.push_back(var.second);
    }
    return answer;
}