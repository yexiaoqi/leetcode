//求两个矩阵的IOU

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
struct Square
{
	int top;
	int left;
	int bottom;
	int right;
	Square() :top(0), left(0), bottom(0), right(0) {}
	Square(int t, int l, int b, int r) :top(t), left(l), bottom(b), right(r) {}
};
double FindIOU(Square &s1, Square &s2)
{
	double cross = 0, unions = 0, iou = 0;
	double s1res = (s1.top - s1.bottom)*(s1.right - s1.left);
	double s2res = (s2.top - s2.bottom)*(s2.right - s2.left);
	if (s2.left >= s1.right || s2.top <= s1.bottom || s1.top <= s2.bottom)
	{
		iou = 0;
		return iou;
	}
	if (s2.top<s1.top)
	{
		if (s2.bottom<s1.bottom)
		{
			//cross = (s2.top-s2.bottom )*(s2.right - s1.left);
			cross = (s2.top - s2.bottom)*(s1.right - s2.left);
		}
		else
		{
			//cross = (s1.bottom - s2.top)*(s1.right - s2.left);
			cross = (s2.top - s1.bottom)*(s1.right - s2.left);
		}
	}
	else
	{
		if (s2.right < s1.right)
		{
			//cross = (s2.bottom - s1.top)*(s2.right - s2.left);
			cross = (s1.top - s2.bottom)*(s2.right - s2.left);
		}
		else
		{
			cross = (s1.right - s2.left)*(s1.top - s2.bottom);
		}
	}
	unions = s1res + s2res - cross;
	iou = cross / unions;
	return iou;
}
int main()
{
	Square s1;
	Square s2;
	double iou = 0;
	cin >> s1.left >> s1.bottom >> s1.right >> s1.top >> s2.left >> s2.bottom >> s2.right >> s2.top;
	//cin >> s1.top >> s1.left >> s1.bottom >> s1.right >> s2.top >> s2.left >> s2.bottom >> s2.right;
	if (s1.left<s2.left)
	{
		iou = FindIOU(s1, s2);
	}
	else
	{
		iou = FindIOU(s2, s1);
	}
	cout << fixed << setprecision(4) << iou << endl;
	return 0;
}
