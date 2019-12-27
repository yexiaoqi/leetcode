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
