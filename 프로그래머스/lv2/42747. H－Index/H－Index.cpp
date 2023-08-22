#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int n, vector<int> c) {
    int l = 0, h = 0;
    for (auto var : c) {
        if (var >= n) h++;
        else l++;
    }
    if (h >= n and l <= n) return true;
    else return false;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater());
    for (int i = citations[0]; i > 0; i--) {
        if (check(i, citations)) {
            answer = i;
            break;
        }
    }
    return answer;
}