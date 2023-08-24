#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (auto var : numbers) answer.push_back(var*2);
    return answer;
}