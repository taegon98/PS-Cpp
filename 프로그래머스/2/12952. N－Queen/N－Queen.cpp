#include <string>
#include <vector>
#include <math.h>

using namespace std;

int arr[13][13], answer;
vector<pair<int, int>> v;

bool check(int n) {
    int y = v.back().first;
    int x = v.back().second;
    
    for (int i = 0; i < v.size() - 1; i++) {
        if (abs(v[i].first - y) == abs(v[i].second - x)) return false;
    }
    
    for (auto var : v) {
        for (int i = 0; i < n; i++) {
            if (i == var.second) continue;
            if (arr[var.first][i]) return false;
        }
        
        for (int i = 0; i < n; i++) {
            if (i == var.first) continue;
            if (arr[i][var.second]) return false;
        }
    }
    return true;
}

void go(int y, int n) {
    if (y == n) {
        answer++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        v.push_back({y, i});
        arr[y][i] = 1;
        if (check(n)) go(y + 1, n);
        v.pop_back();
        arr[y][i] = 0;
    }
}

int solution(int n) {
    go(0, n);
    return answer;
}