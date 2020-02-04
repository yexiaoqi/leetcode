//ͬleetcode 34
//�����Ķ���
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		vector<int> res(2, -1);
		int left = 0;
		int right = data.size();
		while (left<right)
		{
			int mid = left + (right - left) / 2;// int mid = (right + left) / 2;Ҳ�ɣ���ͬѡ��ʽ���ˣ�������ͬ
			if (data[mid]<k)
			{
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (right == data.size() || data[right] != k)
		{
			return 0;
		}
		res[0] = right;
		//left=0;
		right = data.size();
		while (left<right)
		{
			int mid = left + (right - left) / 2;
			if (data[mid] <= k)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		res[1] = right - 1;
		return res[1] - res[0] + 1;
	}
};

//д�ɵ���һ����������ʽ
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		vector<int> res(2, -1);
		res[0] = get(data, k);
		if (res[0] == data.size() || data[res[0]] != k)
		{
			return 0;
		}
		res[1] = get(data, k + 1) - 1;
		return res[1] - res[0] + 1;
	}
	int get(vector<int> data, int k)
	{
		int left = 0;
		int right = data.size();
		while (left<right)
		{
			int mid = (right + left) / 2;
			if (data[mid]<k)
			{
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return right;
	}
};


//��ϰ
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)
		{
			return 0;
		}
		int cnt = 0;
		int begin = 0, end = data.size() - 1;
		int index1 = Search(data, k, begin, end);
		if (index1<0 || data[index1] != k)
		{
			return 0;
		}
		int index2 = Search(data, k + 1, begin, end);
		if (data[index2] == k)
		{
			return index2 - index1 + 1;
		}//������һ����Ҳ��k����ôbegin�����޷��ټ�1�������ҵ��Ĳ��Ǵ��ڵ���k+1�ĵ�һ����
		return index2 - index1;
	}
	int Search(vector<int> &data, int k, int begin, int end)
	{
		int index = 0;
		while (begin<end)
		{
			int mid = (begin + end) / 2;
			if (data[mid] == k)
			{
				if (mid - 1 >= 0 && data[mid - 1] == k)
				{
					end = mid - 1;
					//index = Search(data, k, begin, end);
				}
				else
				{
					return mid;
				}
			}
			else if (data[mid]<k)
			{
				begin = mid + 1;
				//index = Search(data, k, begin, end);
			}
			else
			{
				end = mid - 1;
				//index = Search(data, k, begin, end);
			}
		}
		return begin;
	}
};