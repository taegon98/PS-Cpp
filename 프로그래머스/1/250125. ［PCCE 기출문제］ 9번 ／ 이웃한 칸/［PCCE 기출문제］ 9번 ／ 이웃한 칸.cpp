#include <string>
#include <vector>

using namespace std;

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    
    for (int i = 0; i < 4; i++) {
        int ny = h + dy[i];
        int nx = w + dx[i];
        
        if (ny < 0 or nx < 0 or ny >= n or nx >= n) continue;
        if (board[ny][nx] == board[h][w]) answer++;
    }
        

    return answer;
}