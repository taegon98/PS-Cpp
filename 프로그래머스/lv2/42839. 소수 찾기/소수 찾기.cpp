#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
string str;
int answer, is_prime[10000001] = {false}, v[10000001] = {0};

void go(int depth, string s, int visited[8]) {
    if (s.size() == depth) {
        int num = stoi(s);
        if (!v[num] and !is_prime[num] and num >= 2) {
            answer++;
            v[num] = 1;
        }
        return;
    }
    
    for (int i = 0; i < str.size(); i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        go(depth, s + str[i], visited);
        visited[i] = 0;
    }
}

int solution(string numbers) {
    str = numbers;

    for (int i = 2; i <= pow(10000001, 0.5); i++) {
        if (is_prime[i]) continue;
        for (int j = i * 2; j < 10000001; j += i)
            is_prime[j] = true;
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        int visited[8] = {0};
        go(i + 1, "", visited);
    }
    return answer;
}