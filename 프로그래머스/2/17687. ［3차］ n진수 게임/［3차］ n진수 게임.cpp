#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, string> mp;

string change(int num, int n) {
    string s = "";
    
    while(1) {
        int temp = num % n;
        if (temp >= 10) s += mp[temp];
        else s += to_string(temp);
        
        if (num < n) break;
            
        num /= n;
    }
    reverse(s.begin(), s.end());
  
    return s;
}

string solution(int n, int t, int m, int p) {
    mp[10] = "A"; mp[11] = "B";
    mp[12] = "C"; mp[13] = "D";
    mp[14] = "E";  mp[15] = "F";
    string answer = "";
    p--;
    int turn = 0;
    int cur = 0;
    int idx = 0;
    string s = "";
    
    while(1) {
        if (answer.size() == t) break;
        if (idx == s.size()) {
            idx = 0;
            s = change(cur, n);
            cur++;
        }
        
        if (turn == p) {
            answer += s[idx];
        }
        idx++;
        turn = (turn + 1) % m;
    }
    return answer;
}