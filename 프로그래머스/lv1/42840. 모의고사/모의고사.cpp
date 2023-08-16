#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int m1[] = {1, 2, 3, 4, 5};
    int m2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int m3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int p1 = 0, p2 = 0, p3 = 0;
    vector<int> v(3);
    for (auto var : answers) {
        if (m1[p1] == var) v[0]++;
        if (m2[p2] == var) v[1]++;
        if (m3[p3] == var) v[2]++;
        p1 = (p1 + 1) % 5;
        p2 = (p2 + 1) % 8;
        p3 = (p3 + 1) % 10;
    }
    
    int max_val = *max_element(v.begin(), v.end());
    if (v[0] == max_val) answer.push_back(1);
    if (v[1] == max_val) answer.push_back(2);
    if (v[2] == max_val) answer.push_back(3);
    
    return answer;
}