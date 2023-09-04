#include <string>
#include <map>
using namespace std;
int arr[12][12], visited[12][12][5], cur_y = 6, cur_x = 6;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
map<char, int> mp;

int solution(string dirs) {
    int answer = 0;
    mp['U'] = 1, mp['D'] = 2, mp['L'] = 3, mp['R'] = 4;
    
    for (auto var : dirs) {
        int ny, nx, cur = mp[var];
        if (cur == 1) {
            ny = cur_y + dy[0];
            nx = cur_x + dx[0];
        }
        if (cur == 2) {
            ny = cur_y + dy[1];
            nx = cur_x + dx[1];
        }
        if (cur == 3) {
            ny = cur_y + dy[2];
            nx = cur_x + dx[2];
        }
        if (cur == 4) {
            ny = cur_y + dy[3];
            nx = cur_x + dx[3];
        }
        if (ny <= 0 or nx <= 0 or ny > 11 or nx > 11) continue;
        if (!visited[cur_y][cur_x][cur]) {
            int temp;
            if (cur == 1) temp = 2;
            if (cur == 2) temp = 1;
            if (cur == 3) temp = 4;
            if (cur == 4) temp = 3;
            
            visited[cur_y][cur_x][cur] = 1;
            visited[ny][nx][temp] = 1;
            answer++;
        }
        cur_y = ny; cur_x = nx;
    }
    return answer;
}