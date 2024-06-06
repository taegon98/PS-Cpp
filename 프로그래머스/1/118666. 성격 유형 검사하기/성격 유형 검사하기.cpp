#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<char, int> mp;


void init() {
    mp['R'] = 0; mp['T'] = 0;
    mp['C']= 0; mp['F'] = 0;
    mp['J'] = 0; mp['M'] = 0;
    mp['A'] = 0; mp['N'] = 0;
}

string getAnswer() {
    string answer = "";
    
    if (mp['R'] >= mp['T']) answer += "R";
    else answer += "T";
    
    if (mp['C'] >= mp['F']) answer += "C";
    else answer += "F";
    
    if (mp['J'] >= mp['M']) answer += "J";
    else answer += "M";
    
    if (mp['A'] >= mp['N']) answer += "A";
    else answer += "N";
    
    return answer;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    init();
    
    for (int i = 0; i < survey.size(); i++) {
        int score = choices[i];
        
        if (score > 4) {
            mp[survey[i][1]] += (score - 4);
        }
        else if (score < 4) {
            mp[survey[i][0]] += (4 - score);
        }
    }
    
    return getAnswer();
}