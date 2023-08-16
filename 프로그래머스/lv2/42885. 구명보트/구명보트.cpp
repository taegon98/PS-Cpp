#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater());
    int p1 = 0, p2 = people.size() - 1;

    while(p1 <= p2) {
        if (people[p1] + people[p2] <= limit) {
            p1++; p2--;
        }
        else p1++;
        answer++;
    }
    return answer;
}