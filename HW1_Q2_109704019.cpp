#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n][m], maxx = 0, first2[n] = {}, count2[m] = {};

	for (int i = 0; i < n; i++) {
		int first = 0, count = 0;
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			if (a[i][j] == 1) {
				if (first == -1) {			//for橫的
					maxx = max(maxx, count - 1);
				}
				count = 0;
				first = 1;

				if (first2[j] == -1) {		//	for直的
					maxx = max(maxx, count2[j] - 1);
				}
				count2[j] = 0;
				first2[j] = 1;

			}
			else if (a[i][j] == -1) {			//for橫的
				if (first == 1) {
					maxx = max(maxx, count - 1);
				}
				count = 0;
				first = -1;

				if (first2[j] == 1) {		//	for直的
					maxx = max(maxx, count2[j] - 1);
				}
				count2[j] = 0;
				first2[j] = -1;
			}
			count++;
		}

		for (int j = 0; j < m; j++) {
			count2[j] ++;
		}

	}

	cout << maxx;
	return 0;
}