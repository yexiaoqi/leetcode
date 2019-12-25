//自己做出了
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> num) {
        if(num.size()==0)
        {
            return 0;
        }
        int sum=num[0];
        vector<int> dp(num.size(),0);
        dp[0]=num[0];
        for(int i=1;i<num.size();++i)
        {
            dp[i]=max(dp[i-1]+num[i],num[i]);
            if(sum<dp[i])
            {
                sum=dp[i];
            }
        }
        return sum;
    }
};
