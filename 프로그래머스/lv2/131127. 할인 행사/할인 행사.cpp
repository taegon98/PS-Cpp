#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> mp;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i < want.size(); i++) {
        mp[want[i]] = number[i];
    }
    
    for (int i = 0; i < discount.size() - 9; i++) {
        map<string, int> temp;
        for (int j = i; j < i + 10; j++) {
            temp[discount[j]]++;
        }
        if (mp == temp) answer++;
    }
    
    return answer;
}