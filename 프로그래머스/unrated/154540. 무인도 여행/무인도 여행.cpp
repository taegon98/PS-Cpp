#include <string>
#include <vector>
#include <algorithm>

using namespace std;
char arr[101][101];
int visited[101][101];
int r, c;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int go(int y, int x) {
    int cnt = arr[y][x] - '0';
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 or nx < 0 or ny >= r or nx >= c or visited[ny][nx]) continue;
        if (arr[ny][nx] == 'X') continue;
        else {
            visited[ny][nx] = 1;
            cnt += go(ny, nx);
        }
    }
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    r = maps.size();
    c = maps[0].size();
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = maps[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j] or arr[i][j] == 'X') continue;
            else {
                visited[i][j] = 1;
                answer.push_back(go(i, j));
            }
        }
    }
    if (!answer.size()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}