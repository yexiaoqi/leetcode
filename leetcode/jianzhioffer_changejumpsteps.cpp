//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
class Solution {
public:
	int jumpFloorII(int n) {
		int res = 1 << (n - 1);
		return res;
	}
};