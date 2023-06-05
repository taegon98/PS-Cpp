#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd, lcm, temp1 = n, temp2 = m, tmp;
    while(temp2) {
        tmp = temp1;
        temp1 = temp2;
        temp2 = tmp % temp2;
    }
    gcd = temp1;
    lcm = n * m / gcd;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}