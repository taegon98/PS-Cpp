#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<int, int> mp, ans;
int _rank = 1, cnt, i;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    for (int i = 6; i >= 1; i--)
        ans[i] = _rank++;
    ans[0] = 6;
    
    for (auto var : win_nums) mp[var] = 1;
    
    sort(lottos.begin(), lottos.end(), greater());
    
    for (i = 0; i < lottos.size(); i++) {
        if (lottos[i] != 0) {
            if (mp.find(lottos[i]) != mp.end()) cnt++;
        }
        else break;
    }
    
    answer.push_back(ans[cnt + 6 - i]);
    answer.push_back(ans[cnt]);
    
    return answer;
}