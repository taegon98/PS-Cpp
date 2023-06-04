#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int size = phone_number.size();
    for (int i = 1; i <= size - 4; i++) answer += '*';
    string temp = phone_number.substr(size - 4, 4);
    answer += temp;
    return answer;
}