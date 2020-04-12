

//ÎÒ±¦±¦µÄ´ð°¸
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







