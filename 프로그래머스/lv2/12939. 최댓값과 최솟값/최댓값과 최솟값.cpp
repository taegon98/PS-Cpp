#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    s += " ";
    string answer = "";
    int pos, max_val = -987654321, min_val = 987654321;
    string token;
    while((pos = s.find(" ")) != string::npos) {
        token = s.substr(0, pos);
        
        max_val = max(max_val, stoi(token));
        min_val = min(min_val, stoi(token));
        
        s.erase(0, pos + 1);
    }
    
    answer = to_string(min_val) + " " + to_string(max_val);
    return answer;
}