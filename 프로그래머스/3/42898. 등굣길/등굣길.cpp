#include <string>
#include <vector>

using namespace std;
int arr[101][101], dp[101][101];
int dy[] = {0, 1}, dx[] = {1, 0};

int go(int y, int x, int m, int n) {
    
    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 1 or nx < 1 or ny > n or nx > m) continue;
        if (arr[ny][nx] == -1) continue;
        if (ny == n and nx == m) {
            dp[y][x] += 1;
            continue;
        }
        if (dp[ny][nx]) {
            dp[y][x] += dp[ny][nx];
            continue;
        }
        dp[y][x] += go(ny, nx, m, n);
        dp[y][x] %= 1000000007;
    }
    
    return dp[y][x];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for (auto var : puddles) {
        arr[var[1]][var[0]] = -1;
    }
    
    go(1, 1, m, n);
    
    return dp[1][1] % 1000000007;
}