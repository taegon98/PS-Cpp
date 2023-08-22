#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[100001];

int solution(int number, int limit, int power) {
    int answer = 0;
    fill(arr, arr + number + 1, 1);
    for (int i = 2; i <= number; i++) {
        for (int j = i; j <= number; j += i) arr[j]++;
    }
    
    for (int i = 1; i <= number; i++) {
        if (arr[i] > limit) answer += power;
        else answer += arr[i];
    }
    return answer;
}