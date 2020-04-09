/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void out(char str[], int n) {
	for (int i = 0; i<n; i++) {
		cout << str[i];
	}
	cout << endl;
}

int main()
{
	int n, k;
	int c[10][10];

	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			c[i][j] = 0;
		}
	}

	cin >> n >> k;

	int a, b;
	for (int i = 0; i<k; i++) {
		cin >> a >> b;
		c[a - 1][b - 1] = 1;
		c[b - 1][a - 1] = 1;
	}

	char str[] = "123456789";

	sort(str, str + n);

	bool flag = true;
	for (int i = 1; i<n; i++) {
		if (c[str[i] - '1'][str[i - 1] - '1'] == 1) {
			flag = false;
			break;
		}
	}
	if (flag) {
		out(str, n);
	}

	while (next_permutation(str, str + n)) {
		flag = true;
		for (int i = 1; i<n; i++) {
			if (c[str[i] - '1'][str[i - 1] - '1'] == 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			out(str, n);
		}
	}
	return 0;
}
