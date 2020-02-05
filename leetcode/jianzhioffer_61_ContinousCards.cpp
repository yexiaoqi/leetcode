class Solution {
public:
    bool IsContinuous( vector<int> nums ) {
        if(nums.size()<5)
        {
            return false;
        }
        sort(nums.begin(),nums.end());
        int cntzero=0;
        int i=0;
        while(nums[i]==0)
        {
            ++cntzero;
            ++i;
        }
       int cntgap=nums[nums.size()-1]-nums[i]-(nums.size()-i);
        for(int j=i;j<nums.size()-1;++j)
        {
            if(nums[j]==nums[j+1])
            {
                return false;
            }
        }
        if(cntzero>cntgap)
        {
            return true;
        }
        return false;
    }
};


//��ϰ
class Solution {
public:
	bool IsContinuous(vector<int> nums) {
		if (nums.size() != 5)
		{
			return false;
		}//Ҫ�ж��������������Խ��
		sort(nums.begin(), nums.end());
		int i = 0;
		for (; i<5; ++i)
		{
			if (i<4)
			{
				if (nums[i] != 0 && nums[i] == nums[i + 1])
				{
					return false;
				}
			}//ע������ȵ��������

			if (nums[i] != 0)
			{
				break;
			}
		}
		if (i == 5)
		{
			--i;
		}
		int gap = nums[4] - nums[i] + 1;
		if (gap <= 5)
		{
			return true;
		}
		return false;
	}
};