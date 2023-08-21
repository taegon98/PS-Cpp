#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0, idx = 0;
    sort(score.begin(), score.end(), greater());
    for (int i = 0; i < score.size() / m; i++) {
        int min_val = 987654321;
        for (int j = idx; j < idx + m; j++) {
            min_val = min(min_val, score[j]);
        }
        answer += (min_val * m);
        idx += m;
    }
    return answer;
}