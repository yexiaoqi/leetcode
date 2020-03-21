//只有出现“两高夹一矮”才可能会存到水，
//进而，我们可以想到：每一坐标i上存多少水是由 
//1.其自身高度 2.它左边的最高高度left_most 3.它右边的最高高度right_most三种因素决定的。
//当 min{ left_most, right_most } 小于或等于其自身高度时，它能存的水就是0，
//当min{ left_most,right_most } 大于其自身高度时，这时这三者间出现了“两高夹一矮”的情况，故其能存水，
//而且其存水数 = min{ left_most,right_most } -height。
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
		}//第一遍在 dp[i] 中存入i位置左边的最大值
		mx = 0;
		int res = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			dp[i] = min(dp[i], mx);
			mx = max(mx, height[i]);
			if (dp[i]>height[i])
			{
				res += dp[i] - height[i];
			}//第二遍遍历数组，第二次遍历时找右边最大值，然后和左边最大值比较取其中的较小值，
			//然后跟当前值 A[i] 相比，如果大于当前值，则将差值存入结果
		}
		return res;
	}
};


//一遍遍历方法，双指针
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

//复习
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

//复习
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