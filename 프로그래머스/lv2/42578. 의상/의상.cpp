#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<string, int> mp;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++) {
        mp[clothes[i][1]]++;
    }
    
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        answer *= (iter->second + 1);
    }
    
    return answer - 1;
}