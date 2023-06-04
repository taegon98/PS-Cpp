#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (auto var : arr) {
        if (var % divisor == 0) answer.push_back(var);
    }
    if (!answer.size()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}