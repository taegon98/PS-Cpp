#include <iostream>
using namespace std;
int N;
double arr1[10004], arr2[10004] = { 1.0, }, ret = -987654321;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr1[i];
	for (int i = 1; i <= N; i++) {
		double tmp = arr2[i - 1] * arr1[i];
		if (tmp > arr1[i]) arr2[i] = tmp;
		else arr2[i] = arr1[i];
		ret = ret < arr2[i] ? arr2[i] : ret;
	}
	printf("%.3lf", ret);
}