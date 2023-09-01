#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int arr1[10], arr2[10];
string solution(string X, string Y) {
    string answer = "";
    vector<int> v;
    bool flag = false;
    for (auto var : X) arr1[var - '0']++;
    for (auto var : Y) arr2[var - '0']++;

    for (int i = 0; i < 10; i++) {
        if (arr1[i] == 0 or arr2[i] == 0) continue;
        for (int j = 0; j < min(arr1[i], arr2[i]); j++) {
            v.push_back(i);
        }
    }
    
    sort(v.begin(), v.end(), greater());
    for (auto var : v) {
        if (var != 0) {
            flag = true;
            break;
        }
    }
    if (!v.size()) answer = "-1";
    else if (!flag) answer = "0";
    else
        for (auto var : v) answer += to_string(var);
    
    return answer;
}