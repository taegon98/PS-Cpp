#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int cnt = 0;
    int num = x;
    while(1) {
        answer.push_back(num);
        num += x;
        cnt++;
        if (cnt == n) break;
    }
    return answer;
}