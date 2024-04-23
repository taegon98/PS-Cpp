#include <iostream>
#include<vector>
using namespace std;
int r, c, answer, value, arr[1001][1001];

void check(int y, int x) {
    int p1 = x - 1, p2 = x + value, to = value + 1;
    
    while(p2 < c) {
        int temp = arr[y][p2] - arr[y][p1];
        if (temp < value + 1) return;
        for (int i = 1; i < to; i++) {
            if (temp != arr[y + i][p2] - arr[y + i][p1]) return;
        }
        answer = max(answer, to * to);
        value = to++;
        p2++;
    }
}

int solution(vector<vector<int>> board)
{
    r = board.size();
    c = board[0].size();
    
    for (int i = 0; i < r; i++) {
        arr[i][0] = board[i][0];
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (!board[i][j]) arr[i][j] = 0;
            else arr[i][j] = arr[i][j - 1] + 1;
        }
    }
    
    for (int i = 0; i < r - value; i++) {
        for (int j = 0; j < c - value; j++) {
            if (!arr[i][j]) continue;
            check(i, j);
        }
    }

    return answer;
}