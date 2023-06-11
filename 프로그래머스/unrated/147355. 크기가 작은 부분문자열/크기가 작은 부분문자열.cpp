#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    unsigned long long pnum = stoull(p);
    int psize = p.size();
    for(int i = 0; i < t.size() - psize + 1; i++) {
        string temp = t.substr(i, psize);
        if (stoull(temp) <= pnum) answer++;
    }
    return answer;
}