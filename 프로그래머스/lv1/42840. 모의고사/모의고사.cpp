#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int m1[] = {1, 2, 3, 4, 5};
    int m2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int m3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int p1 = 0, p2 = 0, p3 = 0;
    int ret1 = 0, ret2 = 0, ret3 = 0, max_value = -987654321;
    for (auto var : answers) {
        if (m1[p1] == var) ret1++;
        if (m2[p2] == var) ret2++;
        if (m3[p3] == var) ret3++;
        p1 = (p1 + 1) % 5;
        p2 = (p2 + 1) % 8;
        p3 = (p3 + 1) % 10;
        max_value = max(ret1, ret2);
        max_value = max(max_value, ret3);
    }
    
    if (ret1 == max_value) answer.push_back(1);
    if (ret2 == max_value) answer.push_back(2);
    if (ret3 == max_value) answer.push_back(3);
    
    return answer;
}