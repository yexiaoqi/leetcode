class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        int small=1;
        int big=2;
        while(small<=sum/2)
        {
            int sum2=0;
            sum2=(small+big)*(big-small+1)/2;
            //由于是连续的，差为1的一个序列，那么求和公式是(a0+an)*n/2,不用循环
            /*for(int i=small;i<=big;++i)
            {
                sum2+=i;
            }*/
            if(sum2==sum)
            {
                 vector<int> seq;
                for(int i=small;i<=big;++i)
                {
                    seq.push_back(i);
                }
                res.push_back(seq);
                ++big;
            }
            else if(sum2<sum)
            {
                ++big;
            }
            else{
                ++small;
            }
        }
        return res;
    }
};
