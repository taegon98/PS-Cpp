#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int visited[31];
    fill(visited, visited + 31, 1);
    
    for (auto var : reserve) visited[var]++;
    for (auto var : lost) visited[var]--;
  
    for (int i = 1; i <= n; i++) {
        if (visited[i]) answer++;
        else if(!visited[i]) {
            if (i > 1 and visited[i-1] == 2) {
                visited[i-1]--;
                answer++;
            }
            else if (i < n and visited[i+1] == 2) {
                visited[i+1]--;
                answer++;
            }   
        }
    }
    return answer;
}