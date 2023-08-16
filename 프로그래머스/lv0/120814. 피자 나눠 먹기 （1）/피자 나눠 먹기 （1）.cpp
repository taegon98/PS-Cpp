#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    answer = ceil((double)n / (double)7);
    return answer;
}