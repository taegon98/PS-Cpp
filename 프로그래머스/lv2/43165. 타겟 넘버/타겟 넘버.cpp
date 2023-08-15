#include <string>
#include <vector>

using namespace std;
int t, answer;

void go(int depth, int num, vector<int> numbers) {
    if (depth == numbers.size()) {
        if (num == t) answer++;
        return;
    }
    go(depth + 1, num + numbers[depth], numbers);
    go(depth + 1, num - numbers[depth], numbers);
}

int solution(vector<int> numbers, int target) {
    t = target;
    go(0, 0, numbers);
    return answer;
}