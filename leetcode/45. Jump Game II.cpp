//https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
class Solution {
public:
	int jump(vector<int>& nums) {
		int end = 0;
		int maxpos = 0; //����������Զ��
		int step = 0;
		for (int i = 0; i<nums.size() - 1; ++i)//ע��i<nums.size()-1����Ϊ��ʼ��ʱ��߽��ǵ� 0 ��λ�ã�
//steps �Ѿ��� 1 �ˡ�������һ���պ�������ĩβ����ʱ steps ��ʵ���ü� 1 �ˡ�
//����� i < nums.length��i ����������ʱ�򣬻���� if ����У�steps ���� 1��
		{
			maxpos = max(maxpos, nums[i] + i);
			if (i == end)
			{
				end = maxpos;//�����߽磬�͸��±߽磬���Ҳ�����һ
				step++;
			}
		}
		return step;
	}
};

//��ϰ
class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0, maxres = 0, end = 0;
		for (int i = 0; i<nums.size() - 1; ++i)
		{
			maxres = max(maxres, nums[i] + i);
			if (i == end)
			{
				++step;
				end = maxres;
			}
		}
		return step;
	}
};