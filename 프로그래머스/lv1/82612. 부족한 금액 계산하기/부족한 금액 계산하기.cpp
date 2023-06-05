using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long tot = 0;
    int cnt = 1;
    
    while(count) {
        tot += price * cnt;
        cnt++;
        count--;
    }
    if (money < tot) answer = tot - money;
    
    return answer;
}