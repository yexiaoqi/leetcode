//方法1，自己写出，时间复杂度为O（nlogn）
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        vector<int> res;
        if(input.size()<k)
        {
            return res;
        }
        for(int i=0;i<k;++i)
        {
            res.push_back(input[i]);
        }
        return res;
    }
};
