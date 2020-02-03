class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> res(1,1);
        int i2=0;
        int i3=0;
        int i5=0;
        for(int i=0;i<index;++i)
        {
            int m2=res[i2]*2,m3=res[i3]*3,m5=res[i5]*5;
            int mn=min(m2,min(m3,m5));//注意只有两个数的比较函数
            if(mn==m2)
            {
                ++i2;
            }
            if(mn==m3)
            {
                ++i3;
            }
            if(mn==m5)
            {
                ++i5;
            }
            res.push_back(mn);
        }
        return res[index-1];
    }
};


//复习
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
		{
			return 0;
		}
		vector<int> nums;
		nums.push_back(1);
		int i2 = 0, i3 = 0, i5 = 0;
		for (int i = 1; i<index; ++i)
		{
			int m2 = nums[i2] * 2, m3 = nums[i3] * 3, m5 = nums[i5] * 5;
			int minnum = min(m2, min(m3, m5));
			if (minnum == m2)
			{
				++i2;
			}
			if (minnum == m3)
			{
				++i3;
			}
			if (minnum == m5)
			{
				++i5;
			}
			nums.push_back(minnum);
		}
		return nums.back();
	}
};