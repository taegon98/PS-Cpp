#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[504];

bool cmp(pair<int, double>& a, pair<int, double>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> v;
    double size = stages.size();
    
    for (auto var : stages)
        arr[var]++;
    
    for (int i = 1; i <= N; i++) {
        if (!arr[i]) {
            v.push_back({i, 0});
            continue;
        }
        v.push_back({i, arr[i] / size});
        size -= arr[i];
    }
    sort(v.begin(), v.end(), cmp);
    
    for (auto var : v) {
        answer.push_back(var.first);
    }
    
    return answer;
}