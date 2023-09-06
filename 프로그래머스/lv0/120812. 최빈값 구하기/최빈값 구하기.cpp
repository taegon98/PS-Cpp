#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int cnt[1001];
int solution(vector<int> array) {
    int answer = 0, max_idx, max_value = 0, ok = 0;
    
    for (auto var : array) cnt[var]++;
    for (int i = 0; i < 1001; i++) {
        if (cnt[i] > max_value) {
            max_value = cnt[i];
            max_idx = i;
        }
    }
    
    answer = max_idx;
    
    for (int i = 0; i < 1001; i++) {
        if (max_value == cnt[i]) ok++;
        if (ok == 2) {
            answer = -1;
            break;
        }
    }
     
    return answer;
}