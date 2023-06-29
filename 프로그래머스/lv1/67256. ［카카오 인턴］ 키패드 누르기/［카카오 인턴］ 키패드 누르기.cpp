#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int graph[4][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {-1, 0, -1}}, visited[4][3];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int Find(int r, int c, int num) {
    memset(visited, 0, sizeof(visited));
    int y, x;
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;
    
    while(q.size()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 or nx < 0 or ny > 3 or nx > 2 or visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            if (graph[y][x] == num) return visited[y][x];
            q.push({ny, nx});
        }
    }
    
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int ly = 3, lx = 0, ry = 3, rx = 2;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7) {
            answer += "L";
            lx = 0;
            if (numbers[i] == 1) ly = 0;
            if (numbers[i] == 4) ly = 1;
            if (numbers[i] == 7) ly = 2;
        } 
        else if (numbers[i] == 3 or numbers[i] == 6 or numbers[i] == 9) {
            answer += "R";
            rx = 2;
            if (numbers[i] == 3) ry = 0;
            if (numbers[i] == 6) ry = 1;
            if (numbers[i] == 9) ry = 2;
        }
        else {
            int a = Find(ly, lx, numbers[i]);
            int b = Find(ry, rx, numbers[i]);
            if (a < b) {
                answer += "L";
                lx = 1;
                if (numbers[i] == 2) ly = 0;
                if (numbers[i] == 5) ly = 1;
                if (numbers[i] == 8) ly = 2;
                if (numbers[i] == 0) ly = 3;
            }
            else if (a > b) {
                answer += "R";
                rx = 1;
                if (numbers[i] == 2) ry = 0;
                if (numbers[i] == 5) ry = 1;
                if (numbers[i] == 8) ry = 2;
                if (numbers[i] == 0) ry = 3;
            }
            else if (hand == "left") {
                answer += "L";
                lx = 1;
                if (numbers[i] == 2) ly = 0;
                if (numbers[i] == 5) ly = 1;
                if (numbers[i] == 8) ly = 2;
                if (numbers[i] == 0) ly = 3;
            }
            else if (hand == "right") {
                answer += "R";
                rx = 1;
                if (numbers[i] == 2) ry = 0;
                if (numbers[i] == 5) ry = 1;
                if (numbers[i] == 8) ry = 2;
                if (numbers[i] == 0) ry = 3;
            }
        }
    }
    return answer;
}