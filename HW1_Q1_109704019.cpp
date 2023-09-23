#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1000], maxx = 0, first = 0, count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			if (first == -1) {
				maxx = max(maxx, count-1);
				
			}
			count = 0;
			first = 1;
		}
		else if (a[i] == -1) {
			if (first == 1) {
				maxx = max(maxx, count-1);
				
			}
			count = 0;
			first = -1;
		}

		count++;
	}

	cout << maxx;
	return 0;
}
