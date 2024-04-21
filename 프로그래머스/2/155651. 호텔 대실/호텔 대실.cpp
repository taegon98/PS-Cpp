#include <string>
#include <vector>

using namespace std;
int arr[1500];

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for (auto var : book_time) {
        int from = (stoi(var[0].substr(0, 3)) * 60) + (stoi(var[0].substr(3)));
        int to = (stoi(var[1].substr(0, 3)) * 60) + (stoi(var[1].substr(3)));
        
        for (; from < to + 10; from++) {
            arr[from]++;
        }
    }
    
    for (int i = 0; i < 1500; i++) {
        answer = max(answer, arr[i]);
    }
    return answer;
}