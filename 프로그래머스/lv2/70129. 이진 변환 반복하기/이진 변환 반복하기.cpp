#include <string>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int ret1 = 0, ret2 = 0;
    while(1) {
        int cnt_0 = 0, cnt_1 = 0;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') cnt_0++;
            else cnt_1++;
        }
        if (cnt_1 == 1 and !cnt_0) break;
        
        ret1 += cnt_0;
        while(cnt_1) {
            temp += to_string(cnt_1 % 2);
            cnt_1 /= 2;
        }
        reverse(temp.begin(), temp.end());
        s = temp;
        ret2++;
    }
    answer.push_back(ret2); answer.push_back(ret1);
    return answer;
}