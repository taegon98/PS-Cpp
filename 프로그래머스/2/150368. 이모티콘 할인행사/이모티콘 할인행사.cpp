#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int ret1, ret2, visited[10];

void calc(vector<pair<double, int>> v, vector<vector<int>> u) {
    map<int, double> mp;
    
     for (auto var : v) {
        for (int i = 0; i < u.size(); i++) {
            if (u[i][0] <= var.second) {
                mp[i] += var.first;
            }
        }
     }

    int number_of_ppl = 0;
    double tot_price = 0;
                        
    for (auto var : mp) {
        if (u[var.first][1] <= var.second) {
            number_of_ppl++;
        }
        else tot_price += var.second;
    }
    
    if (ret1 < number_of_ppl) {
        ret1 = number_of_ppl;
        ret2 = tot_price;
    }
    else if (ret1 == number_of_ppl) {
        if (ret2 < tot_price) {
            ret2 = tot_price;
        }
    }
    
    return;
}

void go(vector<pair<double, int>> v, vector<int> e, vector<vector<int>> u, int idx) {
    
    if (v.size() == e.size()) {
        calc(v, u);
        return;
    }
    
    for (int i = idx; i < e.size(); i++) {
        if (visited[i]) continue;
        
        visited[i] = 1;
        for (int j = 10; j <= 40; j += 10) {
            v.push_back({(double)e[i] * (double)((100 - j) / (double)100), j});
            go(v, e, u, i + 1);
            v.pop_back();
        }
        visited[i] = 0;
    } 
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<pair<double, int>> v;
    
    go(v, emoticons, users, 0);
    answer.push_back(ret1); answer.push_back(ret2); 
     
    return answer;
}