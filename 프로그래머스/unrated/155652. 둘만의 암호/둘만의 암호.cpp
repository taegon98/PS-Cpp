#include <string>
#include <vector>
using namespace std;
int arr[27];
string solution(string s, string skip, int index) {
    string answer = "";
    for (auto var : skip) arr[var] = 1;
    for (auto var : s) {
        int cnt = 0;
        int temp = var;
        while(1) {
            if (cnt == index) break;
            temp++;
            if (temp == 123) temp = 97;
            if (arr[temp]) continue;
            else cnt++;
        }
        answer += char(temp);
    }
    return answer;
}