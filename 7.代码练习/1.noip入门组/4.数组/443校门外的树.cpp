#incldue <iostream>
using namespace std;
int main() {
	int L, M, a, b;
	cin >> L >> M;
	int a[L + 5] = {0};
	for (int i = 0; i < M; i++ ) {
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			a[j] = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i <= L; i++) {
		if (!a[i]) sum += 1;
	}
	cout << sum << endl;
	return 0;
}