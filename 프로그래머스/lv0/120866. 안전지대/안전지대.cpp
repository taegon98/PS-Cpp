#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[101][101];
int dy[] = {-1,-1,-1,0,1,1,1,0}, dx[] = {-1,0,1,1,1,0,-1,-1};
int s;

void go(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 or nx < 0 or ny >= s or nx >= s) continue;
        arr[ny][nx] = 1;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    s = board.size();
    
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (board[i][j]) {
                arr[i][j] = 1;
                go(i, j);
            }
        }
    }
    
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (!arr[i][j]) answer++;
        }
    }
    return answer;
}