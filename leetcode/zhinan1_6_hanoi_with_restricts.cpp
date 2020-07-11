#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int step = 0;
void lefttomid(int x)
{
	++step;
	cout << "Move " << x << " " << "from left to mid" << endl;
}
void midtoright(int x)
{
	++step;
	cout << "Move " << x << " " << "from mid to right" << endl;
}
void midtoleft(int x)
{
	++step;
	cout << "Move " << x << " " << "from mid to left" << endl;
}
void righttomid(int x)
{
	++step;
	cout << "Move " << x << " " << "from right to mid" << endl;
}
void hanoi(int n, bool type)
{
	if (!n)
	{
		return;
	}
	hanoi(n - 1, type);
	type ? lefttomid(n) : righttomid(n);
	hanoi(n - 1, !type);
	type ? midtoright(n) : midtoleft(n);
	hanoi(n - 1, type);
}
int main()
{
	int n;
	cin >> n;
	hanoi(n, 1);
	cout << "It will move " << step << " steps.";
	return 0;

}