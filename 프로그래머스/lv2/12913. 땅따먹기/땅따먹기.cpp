#include <iostream>
#include <vector>
using namespace std;
int s, dp[100001][4];

int solution(vector<vector<int>> land)
{
    int answer = 0;
    s = land.size();
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    
    for (int i = 1; i < s; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j] = max(dp[i-1][(j+1)%4] + land[i][j], dp[i-1][(j+2)%4] + land[i][j]);
                dp[i][j] = max(dp[i][j], dp[i-1][(j+3)%4] + land[i][j]);
                answer = max(answer, dp[i][j]);
            }
        }
    }

    return answer;
}