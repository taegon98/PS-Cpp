#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(1) {
        answer++;
        if (a == b) break;
        a = ceil((double)a / 2);
        b = ceil((double)b / 2);
        cout << a<< " "<<b<<"\n";
    }

    return answer - 1;
}