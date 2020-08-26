//下面不对
#include "stdafx.h"
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
#include<sstream>
using namespace std;



double gety(int a, int b, double x)
{
	return a*x*x + x + b;
}
int main()
{
	int T;
	cin >> T;
	vector<int> nums(4, 0);
	for (int i = 0; i < T; ++i)
	{
		cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
		double diff = nums[3] - nums[2];
		diff /= 100000;
		double x1 = nums[2];
		double x2 = nums[2] + diff;
		double area = 0;
		for (int j = 0; j < 100000; ++j)
		{
			double y = gety(nums[0], nums[1], (x1 + x2) / 2);
			area += y*(x2 - x1);
			x1 += diff;
			x2 += diff;
		}
		printf("%.6f", area);
		cout << endl;
		//cout << area<<endl;
	}
	return 0;
}


double gety(int a, int b, double x)
{
	return a*x*x + x + b;
}
int main()
{
	int T;
	cin >> T;
	vector<int> nums(4, 0);
	for (int i = 0; i < T; ++i)
	{
		cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
		double diff = nums[3] - nums[2];
		diff /= 100000;
		double x1 = nums[2];
		double x2 = nums[2] + diff;
		double area = 0;
		for (int j = 0; j < 100000; ++j)
		{
			//double y = gety(nums[0], nums[1], (x1+x2)/2);
			double y1 = gety(nums[0], nums[1], x1);
			double y2 = gety(nums[0], nums[1], x2);
			area += (y2 + y1)*(x2 - x1) / 2.0;
			x1 += diff;
			x2 += diff;
		}
		printf("%.6f", area);
		cout << endl;
		//cout << area<<endl;
	}
	return 0;
}


