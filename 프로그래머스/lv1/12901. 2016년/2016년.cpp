#include <string>
#include <vector>

using namespace std;
int arr[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";
    int cur = b - 1;
    for (int i = 1; i < a; i++) {
        cur += arr[i];
    }
    answer = day[cur % 7];
    return answer;
}