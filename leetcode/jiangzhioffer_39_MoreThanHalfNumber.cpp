class Solution {
public:
    int partition(vector<int> num,int begin,int end)
    {
        int key=num[begin];
        while(begin<end)
        {
            while(begin<end&&num[end]>=num[key])
            {
                --end;
            }
            num[begin]=num[end];
            while(begin<end&&num[begin]<=num[key])
            {
                ++begin;
            }
             num[end]=num[begin];
        }
        num[begin]=key;
        return begin;
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0)
        {
            return 0;
        }
        int mid=numbers.size()>>1;
        int begin=0;
        int end=numbers.size()-1;
        int index=partition(numbers,begin,end);
        while(index!=mid)
        {
            if(index>mid)
            {
                end=index-1;
                index=partition(numbers,begin,end);
            }
            else
            {
                begin=index+1;
                index=partition(numbers,begin,end);
            }
        }
        int res=numbers[mid];
        int times=0;
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==res)
            {
                ++times;
            }
        }
        if(2*times<=numbers.size())
        {
            return 0;
        }
        return res;
    }
};
