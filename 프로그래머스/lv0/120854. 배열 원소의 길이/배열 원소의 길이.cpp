#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for (auto var : strlist) {
        answer.push_back(var.size());
    }
    return answer;
}