#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater());
    int high = citations[0], low = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        int l = 0, h = 0;
        for (auto var : citations) {
            if (var >= mid) h++;
            else l++;
        }
        if (h < mid) {
            high = mid - 1;
        }
        else if (l > mid) {
            low = mid + 1;
        }
        else {
            answer = mid;
            low = mid + 1;
        }
    }
    return answer;
}