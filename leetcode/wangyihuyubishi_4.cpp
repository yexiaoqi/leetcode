网易互娱 - 放盒子


/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

struct Row
{
	int* values;
};

bool Compare_Rows(const Row& a, const Row &b)
{
	if (a.values[0] < b.values[0]) {
		return true;
	}
	else if (a.values[0] > b.values[0]) {
		return false;
	}

	if (a.values[1] < b.values[1]) {
		return true;
	}
	else if (a.values[1] > b.values[1]) {
		return false;
	}

	if (a.values[2] < b.values[2]) {
		return true;
	}
	else if (a.values[2] > b.values[2]) {
		return false;
	}
	return true;
}


int cal(Row* rows, int i, int boxesRowLen, int l, int w, int h) {
	if (i == boxesRowLen) {
		return 0;
	}

	int sum = cal(rows, i + 1, boxesRowLen, l, w, h);

	if (rows[i].values[0] > l && rows[i].values[1] > w && rows[i].values[2] > h) {
		sum = max(sum, 1 + cal(rows, i + 1, boxesRowLen, rows[i].values[0], rows[i].values[1], rows[i].values[2]));
	}

	//cout<<"i:"<<i<<" l:"<<l<<" w:"<<w<<" h:"<<h<<" sum:"<<sum<<" "<<endl;
	return sum;
}

int main()
{
	int boxesRowLen = 3;
	int boxesColLen = 3;
	int boxes[boxesRowLen][boxesColLen] = { { 5,6,3 },{ 5,4,6 },{ 6,6,6 } };

	Row rows[boxesRowLen];

	for (int i = 0; i<boxesRowLen; i++) {
		rows[i].values = boxes[i];
	}

	sort(&rows[0], &rows[boxesRowLen], Compare_Rows);

	/*
	for(int i=0; i<boxesRowLen; i++){
	for(int j=0; j<boxesColLen; j++){
	cout<<rows[i].values[j]<<" ";
	}
	cout<<endl;
	}
	*/

	int res = cal(&rows[0], 0, boxesRowLen, 0, 0, 0);
	cout << res << endl;

	return 0;
}


//我宝宝的答案
struct Row
{
	int* values;
};
class Solution {
public:



	bool Compare_Rows(Row& a, Row &b)
	{
		if (a.values[0] < b.values[0]) {
			return true;
		}
		else if (a.values[0] > b.values[0]) {
			return false;
		}

		if (a.values[1] < b.values[1]) {
			return true;
		}
		else if (a.values[1] > b.values[1]) {
			return false;
		}

		if (a.values[2] < b.values[2]) {
			return true;
		}
		else if (a.values[2] > b.values[2]) {
			return false;
		}
		return true;
	}


	int cal(Row* rows, int i, int boxesRowLen, int l, int w, int h) {
		if (i == boxesRowLen) {
			return 0;
		}

		int sum = cal(rows, i + 1, boxesRowLen, l, w, h);

		if (rows[i].values[0] > l && rows[i].values[1] > w && rows[i].values[2] > h) {
			sum = max(sum, 1 + cal(rows, i + 1, boxesRowLen, rows[i].values[0], rows[i].values[1], rows[i].values[2]));
		}

		//cout<<"i:"<<i<<" l:"<<l<<" w:"<<w<<" h:"<<h<<" sum:"<<sum<<" "<<endl;
		return sum;
	}



	int maxBoxes(int** boxes, int boxesRowLen, int* boxesColLen) {
		Row rows[boxesRowLen];

		for (int i = 0; i<boxesRowLen; i++) {
			rows[i].values = boxes[i];
		}

		sort(&rows[0], &rows[boxesRowLen], Compare_Rows);

		/*
		for(int i=0; i<boxesRowLen; i++){
		for(int j=0; j<boxesColLen; j++){
		cout<<rows[i].values[j]<<" ";
		}
		cout<<endl;
		}
		*/

		int res = cal(&rows[0], 0, boxesRowLen, 0, 0, 0);
		cout << res << endl;

		return res;
	}
};







