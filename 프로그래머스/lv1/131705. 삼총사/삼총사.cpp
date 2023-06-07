#include <string>
#include <vector>
#include <iostream>

using namespace std;
int ret;

void go(vector<int> number, int idx, int tot, int cnt) {
    if (cnt == 3) {
        if (!tot) ret++;
        else return;
    }
    for (int i = idx; i < number.size(); i++) {
        go(number, i + 1, tot + number[i], cnt + 1);
    }
}

int solution(vector<int> number) {
    int answer = 0;
    go(number, 0, 0, 0);
    answer = ret;
    return answer;
}