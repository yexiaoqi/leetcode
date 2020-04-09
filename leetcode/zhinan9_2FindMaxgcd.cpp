#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include <memory>
#include<time.h>
#include<queue>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

int FindMax(int m, int n)
{
	return n == 0 ? m : FindMax(n, m%n);
}
int main()
{
	int m, n;
	cin >> m >> n;
	cout << FindMax(m, n) << endl;
	return 0;
}
