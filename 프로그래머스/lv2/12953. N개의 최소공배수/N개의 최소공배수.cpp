#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int temp;
    
    while(1) {
        if (b == 0) return a;
        else {
            temp = b;
            b = a % b;
            a = temp;
        }
    }
}
    
int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        answer = answer * arr[i] / gcd(answer, arr[i]);
    }

    return answer;
}