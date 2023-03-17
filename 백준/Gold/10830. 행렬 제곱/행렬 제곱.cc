#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll N, b;
bool flag = false;

vector<vector<ll>> calc(vector<vector<ll>>& A, vector<vector<ll>>& B) {
	vector<vector<ll>> ret(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % 1000;
			}
		}
	}
	return ret;
}
void multi(vector<vector<ll>>& m) {
	vector<vector<ll>> ret(N, vector<ll>(N));

	for (int i = 0; i < N; i++) ret[i][i] = 1;

	while (b > 0) {
		if (b % 2 == 0) {
			m = calc(m, m);
			b /= 2;
		}
		else {
			ret = calc(ret, m);
			b -= 1;
		}
	}
	m = ret;
}

int main() {
	int i, j;
	cin >> N >> b;
	vector<vector<ll>> matrix(N, vector<ll>(N));

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) cin >> matrix[i][j];
	}
	
	multi(matrix);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) cout << matrix[i][j] << " ";
		cout << matrix[i][j] << "\n";
	}
	return 0;
}