#include <string>
#include <map>
using namespace std;

map<string, int> mp1, mp2;

int solution(string str1, string str2) {
    int numer = 0, denom = 0;
    
    for (int i = 0; i < str1.size() - 1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
            string s = "";
            s.push_back(tolower(str1[i]));
            s.push_back(tolower(str1[i + 1]));
            mp1[s]++;
        } 
    }
    
    for (int i = 0; i < str2.size() - 1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            string s = "";
            s.push_back(tolower(str2[i]));
            s.push_back(tolower(str2[i + 1]));
            mp2[s]++;
        } 
    }

    for (auto var : mp1) {
        if (mp2[var.first]) {
            numer += (min(var.second, mp2[var.first]));
            denom += (max(var.second, mp2[var.first]));
        } else {
            denom += (var.second);
        }
    }
    
    for (auto var : mp2) {
        if (!mp1[var.first]) denom += (var.second);
    }
    
    if (!numer && !denom) return 65536;
    else return ((double)numer / (double)denom * 65536);
}