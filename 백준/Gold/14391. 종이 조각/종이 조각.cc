#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int N, M, ret = -987654321;
int arr[4][4], tmp[4][4], num[20] = { 0 };

int check_row(int f) {
	int value = 0;
	for (int i = 0; i < N; i++) {
		string str;
		for (int j = 0; j < M; j++) {
			if (f == tmp[i][j]) str += to_string(arr[i][j]);
			else {
				if (str.size() != 0) value += stoi(str);
				str = "";
			}
		}
		if (str.size() != 0) value += stoi(str);
	}
	return value;
}

int check_col(int f) {
	int value = 0;
	for (int i = 0; i < M; i++) {
		string str;
		for (int j = 0; j < N; j++) {
			if (f == tmp[j][i]) str += to_string(arr[j][i]);
			else {
				if (str.size() != 0) value += stoi(str);
				str = "";
			}
		}
		if (str.size() != 0) value += stoi(str);
	}
	return value;
}

void go(int n) {
	memset(tmp, 0, sizeof(tmp));
	memset(num, 0, sizeof(num));
	int idx = 0;
	for (int i = 0; i < N * M; i++) {
		if (n & (1 << i)) num[N * M - i - 1] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) tmp[i][j] = num[idx++];
	}
	ret = max(ret, check_row(0) + check_col(1));
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) scanf("%1d", &arr[i][j]);
	}
	for (int i = 0; i < (1 << (N * M)); i++) go(i);
	cout << ret;
}