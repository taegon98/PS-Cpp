#include <string>
#include <vector>
#include <iostream>
using namespace std;
char arr[] = {'A', 'E', 'I', 'O', 'U'};
int answer;

bool go(string s, int depth, string w) {
   // cout << s <<"\n";
    
    if (depth >= 5) {
        if (s == w) return true;
        else return false;
    }
    if (depth == w.size()) {
        if (s == w) return true;
    }
    
    for (int i = 0; i < 5; i++) {
        s += arr[i]; 
        answer++;
        if (go(s, depth + 1, w)) return true;;
        s.pop_back();
    }
    return false;
}

int solution(string word) {
    go("", 0, word);
    return answer;
}