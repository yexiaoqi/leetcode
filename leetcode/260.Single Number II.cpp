//同剑指offer 56_01
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff=0;
        for(int i=0;i<nums.size();++i)
        {
            diff^=nums[i];
        }
        diff&=-diff;//a &= -a 可以取出最右端为 ‘1’ 的位
        vector<int> res(2,0);
        for(int i=0;i<nums.size();++i)
        {
            if(diff&nums[i])
            {
                res[0]^=nums[i];
            }
            else
            {
                res[1]^=nums[i];
            }
        }
        return res;
    }
};


//复习
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return vector<int>();
		}
		int sum = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			sum ^= nums[i];
		}
		int  first = 0x1;
		while ((sum&first) == 0)
		{
			first <<= 1;
		}
		// for(;first<=sum;first<<=1)//这样不对，如果sum是负数就进不了循环了
		// {
		//     if((sum&first)!=0)
		//     {
		//         break;
		//     }
		// }
		int res1 = 0, res2 = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (first&nums[i])
			{
				res1 ^= nums[i];
			}
			else
			{
				res2 ^= nums[i];
			}
		}
		vector<int> res{ res1,res2 };
		return res;
	}
};