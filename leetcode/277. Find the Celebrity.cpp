//O(n^2)
//������һά�����������ÿ���˵����˺�ѡ״̬����ʼ����ʼ��Ϊ true����ʾÿ���˶������˺�ѡ�ˣ�
//Ȼ������һ����һ���˵���֤���Ƿ�Ϊ���ˣ����ں�ѡ��i�����Ǳ�������������j�����i��ʶj������j����ʶi
//��˵��i�����������ˣ���ô���Ǳ����Ϊ false��Ȼ����֤��һ����ѡ�ߣ���֮���i����ʶj������j��ʶi��
//˵��j�����������ˣ����֮������ÿ����ѡ��i�����������һȦ�����ѡ��״̬��Ϊ true��˵��i�������ˣ����ؼ��ɣ�
//���������������û���ҵ����ˣ����� - 1
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		vector<bool> people(n, true);
		for (int i = 0; i<n; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				if (people[i] && i != j)
				{
					if (knows(i, j) || !knows(j, i))
					{
						people[i] = false;
						break;
					}
					else
					{
						people[j] = false;
					}
				}
			}
			if (people[i])
			{
				return i;
			}
		}
		return -1;
	}
};


//O(n)
//�趨��ѡ�� res Ϊ0��ԭ�����ȱ���һ�飬���ڱ���������i������ѡ�� res ��ʶi���򽫺�ѡ�� res ��Ϊi��
//���һ�����������������ѡ�� res �Ƿ����������ˣ���������жϲ������ˣ��򷵻� - 1�������û�г�ͻ��
//���� res
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		int res = 0;
		for (int i = 1; i<n; ++i)
		{
			if (knows(res, i))
			{
				res = i;
			}
		}
		for (int i = 0; i<n; ++i)
		{
			if (res != i && (knows(res, i) || !knows(i, res)))
			{
				return -1;
			}
		}
		return res;
	}
};


//����Ľⷨ
//�����Խ�һ������ API �ĵ��������Һ�ѡ�ߵķ�����������ͬ����������֤��ʱ�򣬷�Ϊ���Σ�����֤��ѡ��ǰ��������ˣ�
//����ѡ����ʶ�κ��ˣ������κ��˲���ʶ��ѡ�ߣ�ֱ�ӷ��� - 1������֤��ѡ�ߺ�����ˣ�
//��ʱ��ֻ��Ҫ��֤�Ƿ����˲���ʶ��ѡ�߾Ϳ����ˣ�
//��Ϊ�������ʼ�Һ�ѡ�ߵ�ʱ����Ѿ���֤�˺�ѡ�߲�����ʶ������κ���
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		int res = 0;
		for (int i = 1; i<n; ++i)
		{
			if (knows(res, i))
			{
				res = i;
			}
		}
		for (int i = 0; i<res; ++i)
		{
			if (knows(res, i) || !knows(i, res))
			{
				return -1;
			}
		}
		for (int i = res + 1; i<n; ++i)
		{
			if (!knows(i, res))
			{
				return -1;
			}
		}
		return res;
	}
};