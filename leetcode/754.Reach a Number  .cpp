//���ǵĵڶ��� trick ���ǣ�������Ŀ��ֵ�Ĳ�ֵdΪż��ʱ��ֻҪ���� d / 2 ���ľ���ȡ�������ܵõ�Ŀ��ֵ����ʱ�Ĳ�����Ϊ����Ŀ��ֵ�Ĳ�������ô�����dΪ����ʱ���ҵ�ǰΪ��n������ô���ǿ���һ�� n + 1 ����ż����� n + 1 Ϊ��������ô���� n + 1 ������õ��Ĳ�ֵ��Ϊż���ˣ������������ n + 1 Ϊż������ô���ü��� n + 2 ��������������ò�ֵΪż���������Ͷ������������
class Solution {
public:
	int reachNumber(int target) {
		target = abs(target);
		long n = ceil((-1.0 + sqrt(1 + 8.0*target)) / 2);//Ҫ��8.0���������ȥ����int��
		long sum = n*(n + 1) / 2;
		cout << sum;
		if (sum == target)
		{
			return n;
		}
		long resi = sum - target;
		if (!(resi & 0x1))
		{
			return n;
		}
		else
		{
			if (n & 0x1)
			{
				return n + 2;
			}
			else
			{
				return n + 1;
			}
		}
	}
};