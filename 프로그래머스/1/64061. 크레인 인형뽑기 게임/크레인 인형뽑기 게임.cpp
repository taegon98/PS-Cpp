#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> _s;
    int r = board.size();

    for (auto var : moves) {
        for (int i = 0; i < r; i++) {
            if (board[i][var - 1]) {
                if (!_s.empty() and _s.top() == board[i][var - 1]) {
                    _s.pop();
                    answer+=2;
                }
                else {
                    _s.push(board[i][var - 1]);
                }
                board[i][var - 1] = 0;
                break;
            }
        }
    }
    
    return answer;
}