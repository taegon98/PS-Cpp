#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (auto var : arr) {
        answer += var;
    }
    return answer / arr.size();
}