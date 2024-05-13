#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int ret = -987654321;
map<string, char> mp;

vector<string> split(string s) {
    vector<string> v;
    char delimiter = ',';
    int idx;
    
    while((idx = s.find(delimiter)) != string::npos) {
        v.push_back(s.substr(0, idx));
        s = s.substr(idx + 1);
    }
    
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (i != s.size() - 1 and s[i + 1] == '#') {
            string str = "";
            str.push_back(s[i]);
            str.push_back(s[i + 1]);
            temp += mp[str];
            i++;
        }
        else temp += s[i];
    }
    cout << temp<<"\n";
    
    v.push_back(temp);
    return v;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    mp["A#"] = 'H'; mp["C#"] = 'I'; mp["D#"] = 'J'; mp["F#"] = 'K'; mp["G#"] = 'L';
    string temp = "";
    
    for (int i = 0; i < m.size(); i++) {
        if (i != m.size() - 1 and m[i + 1] == '#') {
            string str = "";
            str.push_back(m[i]);
            str.push_back(m[i + 1]);
            temp += mp[str];
            i++;
        }
        else temp += m[i];
    }
    m = temp;
    
    for (auto var : musicinfos) {
        vector<string> v = split(var);
        int h = stoi(v[1].substr(0, 2)) - stoi(v[0].substr(0, 2));
        int min = stoi(v[1].substr(3)) - stoi(v[0].substr(3));
        int tot = (h * 60) + min;
        
        int q = tot / v[3].size();
        int d = tot % v[3].size();
        
        string s = "";
        for (int i = 0; i < q; i++) {
            s += v[3];
        }
        s += v[3].substr(0, d);

        int idx = s.find(m);

        if (idx != string::npos and ret < (int)s.size()) {
            answer = v[2];
            ret = (int)s.size();
        }
    }
                
    if (answer.empty()) answer = "(None)";
    return answer;
}