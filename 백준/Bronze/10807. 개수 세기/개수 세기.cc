#include <iostream>
#include <unordered_map>
using namespace std;

int N, v, tmp;
unordered_map<int, int> map;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp; map[tmp]++;
	}
	cin >> v;
	cout << map[v];
}