#include<bits/stdc++.h>
using namespace std;
// mã hóa các màu b?ng các s? nguyên 0, 1, 2 ?? bi?u di?n l?n l??t m?u ??, tr?ng và xanh t??ng ?ng
int cnt[1000000] = { 0 };
void sapxep(int a[], int n) {
	int K = -1000000;
	for (int i = 0; i < n; i++) {
		K = max(K, a[i]);
	}
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << " ";
		}
	}
}
int main() {
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sapxep(a, n);
}