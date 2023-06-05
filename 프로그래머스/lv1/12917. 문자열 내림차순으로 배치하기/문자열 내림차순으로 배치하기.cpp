#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) { return a > b; }

string solution(string s) {
    string answer = "";
    answer = s;
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}