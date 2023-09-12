#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int psum1[1000001], psum2[1000001];
map<int, int> mp1, mp2;

int check(int n) {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (psum1[i] == psum2[i + 1]) cnt++;
    }
    return cnt;
}

int solution(vector<int> topping) {
    int answer = -1;
    for (int i = 1; i <= topping.size(); i++) {
        if (mp1.find(topping[i - 1]) == mp1.end()) {
            mp1[topping[i - 1]]++;
            psum1[i] = psum1[i - 1] + 1;
        }
        else psum1[i] = psum1[i - 1];
    }
    
    for (int i = topping.size(); i >= 1; i--) {
        if (mp2.find(topping[i - 1]) == mp2.end()) {
            mp2[topping[i - 1]]++;
            psum2[i] = psum2[i + 1] + 1;
        }
        else psum2[i] = psum2[i + 1];
    }
    answer = check(topping.size());
    return answer;
}