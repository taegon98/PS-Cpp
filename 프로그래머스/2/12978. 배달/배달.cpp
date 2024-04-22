#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> v[51];
map<pair<int, int>, int> mp;
set<int> st;
int visited[51];

void go(int n, int w, int c) {
    if (c < w) {
        return;
    }
    else {
        st.insert(n);
    }
    
    for (auto var : v[n]) {
        if (visited[var]) continue;
        visited[var] = 1;
        go(var, w + mp[{n, var}], c);
        visited[var] = 0;
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (auto var : road) {
        if (mp[{var[0], var[1]}]) {
            if (var[2] < mp[{var[0], var[1]}]) {
               mp[{var[0], var[1]}] = var[2];
               mp[{var[1], var[0]}] = var[2];
            }      
            continue;
        }
        if (mp[{var[1], var[0]}]) {
            if (var[2] < mp[{var[1], var[0]}]) {
                mp[{var[0], var[1]}] = var[2];
                mp[{var[1], var[0]}] = var[2];
            }     
            continue;
        }
        v[var[0]].push_back(var[1]);
        v[var[1]].push_back(var[0]);
        mp[{var[0], var[1]}] = var[2];
        mp[{var[1], var[0]}] = var[2];
    }
    
    go(1, 0, K);
    answer = st.size();
    for (auto var : st) cout << var <<" ";
    return answer;
}