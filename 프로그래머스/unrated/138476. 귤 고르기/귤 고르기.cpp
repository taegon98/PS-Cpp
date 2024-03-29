#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> v(10000001);
int solution(int k, vector<int> tangerine) {
    int answer = 0, tot = 0, idx = 0;
    
    for (auto var : tangerine) {
        v[var]++;
    }
    
    int num = *max_element(tangerine.begin(), tangerine.end());
    sort(v.begin(), v.begin() + num + 1, greater());
    
    while(1) {
        answer++;
        tot += v[idx++];
        if (tot >= k) break;
    }
    return answer;
}