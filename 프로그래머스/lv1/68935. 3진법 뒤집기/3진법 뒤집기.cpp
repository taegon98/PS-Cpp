#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int t = 1;
    string s = "";
    while (n >= 3) {
        s += to_string(n % 3);
        n /= 3;
    }
    s += to_string(n);
    for (int i = s.size() - 1; i >= 0; i--) {
        answer += (s[i] - '0') * t;
        t *= 3;
    }
    
    return answer;
}