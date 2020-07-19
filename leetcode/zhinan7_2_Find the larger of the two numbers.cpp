//https://www.nowcoder.com/questionTerminal/02ae5ccb63064bbdb2366417d8b70ff3
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
#include<limits.h>
#include<math.h>
using namespace std;
int flip(int num)
{
	return !num;
}
int sign(int num)
{
	return flip((num >> 31) & 1);
}
int main()
{
	int a, b;
	cin >> a >> b;
	long c = a - b;
	int sa = sign(c);
	int sb = flip(sa);
	cout << sa*a + sb*b;
	return 0;
}