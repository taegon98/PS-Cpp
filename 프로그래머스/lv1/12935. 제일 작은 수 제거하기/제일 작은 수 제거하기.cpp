#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int INF = 987654321;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < INF) INF = arr[i];
    }
    arr.erase(remove(arr.begin(), arr.end(), INF), arr.end());
    if (!arr.size()) answer.push_back(-1);
    else answer = arr;
    return answer;
}