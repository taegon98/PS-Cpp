#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<string>& s1, const vector<string>& s2) {
    string a = "", b = "";
    
    for (auto var : s1[0]) {
        if (isalpha(var))
            a += toupper(var);
        else
            a += var;
    }
    for (auto var : s2[0]) {
        if (isalpha(var))
            b += toupper(var);
        else
            b += var;
    }
    
    if (a == b) {
        if (stoi(s1[1]) == stoi(s2[1])) {
            return stoi(s1[s1.size() - 1]) < stoi(s2[s2.size() - 1]);
        }
        return stoi(s1[1]) < stoi(s2[1]);
    }

    return a < b;
}

vector<vector<string>> v;

vector<string> split(string s1) {
    vector<string> v;
    int idx, i = 0;

    for (; i < s1.size(); i++) {
        if (isdigit(s1[i])) {
            string s2 = s1.substr(0, i);
            v.push_back(s2);
            idx = i;
            break;
        }
    }

    for (; i < s1.size(); i++) {
        if (!isdigit(s1[i]) or i - idx == 5) {
            string s2 = s1.substr(idx, i - idx);
            v.push_back(s2);
            v.push_back(s1.substr(i));
            return v;
        }
    }
    v.push_back(s1.substr(idx));
    
    return v;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int idx = 1;
    
    for (auto var : files) {
        v.push_back(split(var));
        v[v.size() - 1].push_back(to_string(idx++));
    }
    
    stable_sort(v.begin(), v.end(), cmp);
    
    for (auto var : v) {
        string temp = "";
        for (int i = 0; i < var.size() - 1; i++) temp += var[i];
        answer.push_back(temp);
    }
    
    return answer;
}