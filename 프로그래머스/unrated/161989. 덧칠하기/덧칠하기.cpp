#include <string>
#include <vector>

using namespace std;
int visited[100001];
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for (int i = section.size() - 1; i >= 0; i--) {
        if (visited[section[i]] or section[i] - m < 0) continue;
        for (int j = section[i]; j > section[i] - m; j--) visited[j] = 1;
        answer++;
    }

    for (auto var : section) {
        if (visited[var] or var + m > n + 1) continue;
        for (int j = var; j < var + m; j++) visited[j] = 1;
        answer++;
    }
    return answer;
}