#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int tot1 = 0, tot2 = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < A.size(); i++) {
        tot1 += (A[i] * B[i]);
    }
    sort(B.begin(), B.end(), cmp);
    for (int i = 0; i < A.size(); i++) {
        tot2 += (A[i] * B[i]);
    }
    answer = min(tot1, tot2);
    return answer;
}