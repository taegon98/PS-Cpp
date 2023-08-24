#include <string>
#include <vector>

using namespace std;
vector<int> answer(2);
vector<int> solution(vector<int> num_list) {
    for (auto var : num_list) {
        if (var % 2 == 1) answer[1]++;
        else answer[0]++;
    }
    return answer;
}