#include <string>
#include <vector>
using namespace std;
char arr[] = {'A', 'E', 'I', 'O', 'U'};
int answer;

bool go(string s, int depth, string w) {
    if (s == w) return true;
    if (depth >= 5) {
        if (s == w) return true;
        else return false;
    }  
    
    for (int i = 0; i < 5; i++) {
        s += arr[i]; 
        answer++;
        if (go(s, depth + 1, w)) return true;
        s.pop_back();
    }
    return false;
}

int solution(string word) {
    go("", 0, word);
    return answer;
}