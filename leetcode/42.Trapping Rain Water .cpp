//ֻ�г��֡����߼�һ�����ſ��ܻ�浽ˮ��
//���������ǿ����뵽��ÿһ����i�ϴ����ˮ���� 
//1.������߶� 2.����ߵ���߸߶�left_most 3.���ұߵ���߸߶�right_most�������ؾ����ġ�
//�� min{ left_most, right_most } С�ڻ����������߶�ʱ�����ܴ��ˮ����0��
//��min{ left_most,right_most } ����������߶�ʱ����ʱ�����߼�����ˡ����߼�һ����������������ܴ�ˮ��
//�������ˮ�� = min{ left_most,right_most } -height��
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		vector<int> dp(n, 0);
		int mx = 0;
		for (int i = 0; i<n; ++i)
		{
			dp[i] = mx;
			mx = max(mx, height[i]);
		}//��һ���� dp[i] �д���iλ����ߵ����ֵ
		mx = 0;
		int res = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			dp[i] = min(dp[i], mx);
			mx = max(mx, height[i]);
			if (dp[i]>height[i])
			{
				res += dp[i] - height[i];
			}//�ڶ���������飬�ڶ��α���ʱ���ұ����ֵ��Ȼ���������ֵ�Ƚ�ȡ���еĽ�Сֵ��
			//Ȼ�����ǰֵ A[i] ��ȣ�������ڵ�ǰֵ���򽫲�ֵ������
		}
		return res;
	}
};


//һ�����������˫ָ��
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int l = 0, r = n - 1;
		int minx = 0, res = 0;
		while (l<r)
		{
			minx = min(height[l], height[r]);
			if (minx == height[l])
			{
				++l;
				while (l<r&&height[l]<minx)
				{
					res += minx - height[l];
					l++;
				}
			}
			else
			{
				--r;
				while (l<r&&height[r]<minx)
				{
					res += minx - height[r];
					--r;
				}
			}
		}
		return res;
	}
};

//��ϰ
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0)
		{
			return 0;
		}
		int res = 0;
		vector<int> dp(n, 0);
		int mx = 0;
		for (int i = 0; i<n; ++i)
		{
			dp[i] = mx;
			mx = max(mx, height[i]);
		}
		mx = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			dp[i] = min(dp[i], mx);
			mx = max(mx, height[i]);
			if (height[i]<dp[i])
			{
				res += dp[i] - height[i];
			}
		}
		return res;
	}
};

//��ϰ
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0)
		{
			return 0;
		}
		int left = 0, right = n - 1;
		int res = 0;
		while (left<right)
		{
			int mn = min(height[left], height[right]);
			if (mn == height[left])
			{
				++left;
				while (left<right&&height[left]<mn)
				{
					res += mn - height[left];
					++left;
				}
			}
			else
			{
				--right;
				while (left<right&&height[right]<mn)
				{
					res += mn - height[right];
					--right;
				}
			}
		}
		return res;
	}
};