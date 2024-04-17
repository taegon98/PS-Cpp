#include <string>
#include <vector>
#include <map>
using namespace std;
int answer = 987654321, p;
map<pair<int, string>, int> mp;

void go(int idx, int tot, vector<int> v, vector<string> m) {
    if (idx > m.size() or !p) {
        answer = min(answer, tot);
        return;
    }
    
    for (int i = 0; i < v.size(); i++) {
        if (!v[i]) continue;
        v[i]--; p--;
        int cnt = 0, temp = 0;
        for (int j = idx; j < m.size(); j++) {
            temp += mp[{i, m[j]}];
            cnt++;
            if (cnt == 5) break;
        }
        go(idx + 5, tot + temp, v, m);
        v[i]++; p++;
    }
}

void init() {
    mp[{0, "diamond"}] = 1;
    mp[{0, "iron"}] = 1;
    mp[{0, "stone"}] = 1;
    
    mp[{1, "diamond"}] = 5;
    mp[{1, "iron"}] = 1;
    mp[{1, "stone"}] = 1;
    
    mp[{2, "diamond"}] = 25;
    mp[{2, "iron"}] = 5;
    mp[{2, "stone"}] = 1;
}

int solution(vector<int> picks, vector<string> minerals) {
    init();
    for (auto var : picks)  p += var;
    
    go(0, 0, picks, minerals);
    return answer;
}