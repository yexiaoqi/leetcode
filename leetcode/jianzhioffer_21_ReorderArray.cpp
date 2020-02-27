//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
//�Լ��Ľⷨ
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		queue<int> jishu;
		queue<int> oushu;
		for (int i = 0; i<int(array.size()); ++i)
		{
			if (array[i] & 0x1)
			{
				jishu.push(array[i]);
			}
			else {
				oushu.push(array[i]);
			}
		}
		int j = 0;
		while (!jishu.empty())
		{
			array[j] = jishu.front();
			++j;
			jishu.pop();
		}
		while (!oushu.empty())
		{
			array[j] = oushu.front();
			++j;
			oushu.pop();
		}
	}
};

//���½�queue��
/**
* 1.Ҫ�뱣֤ԭ�д�����ֻ��˳���ƶ������ڽ�����
* 2.i�������ұ������ҵ���һ��ż����
* 3.j��i+1��ʼ����ң�ֱ���ҵ���һ��������
* 4.��[i,...,j-1]��Ԫ���������һλ������ҵ�����������iλ�ã�Ȼ��i++��
* 5.�Kֹ�l����j�����v����ʧ����
*/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int size = array.size();
		if (size <= 1)
		{
			return;
		}
		int i = 0, j = 1;
		while (i<size)
		{
			j = i + 1;
			if (!(array[i] & 0x1))
			{
				while (!(array[j] & 0x1))
				{
					if (j == size - 1)
					{
						return;
					}
					++j;
				}
				int cnt = j - i;
				int tmp = array[j];
				while (cnt)
				{
					array[i + cnt] = array[i + cnt - 1];
					--cnt;
				}
				array[i] = tmp;
			}
			++i;
		}
	}
};

//�����Ҫ��֤������������ż����ż��֮������λ�ò��䣬����������һ����������ָ��ǰ�����м��������

//��ϰ
class Solution {
public:
	void reOrderArray(vector<int> &nums) {
		vector<int> tmp;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] & 0x1)
			{
				tmp.push_back(nums[i]);
			}
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (!(nums[i] & 0x1))//���������ȼ�����&��һ��Ҫ��()
			{
				tmp.push_back(nums[i]);
			}
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			nums[i] = tmp[i];
		}
	}
};


