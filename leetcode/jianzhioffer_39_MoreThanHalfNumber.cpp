//自己的解法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int,int> mapping;
        int size=numbers.size();
        set<int> numset(numbers.begin(),numbers.end());
        for(int i=0;i<size;++i)
        {
            ++mapping[numbers[i]];          
            if(mapping[numbers[i]]>(size/2))
               {
                   return numbers[i];
               }
        }
        return 0;
    }
};


//方法1，O（n）时间复杂度，o（1）空间复杂度
class Solution {
public:
    int partition(vector<int> &num,int begin,int end)
    {
        int key=num[begin];
        while(begin<end)
        {
            while(begin<end&&num[end]>=key)
            {
                --end;
            }
            num[begin]=num[end];
            while(begin<end&&num[begin]<=key)
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
//方法二，O（n）时间复杂度，o（1）空间复杂度
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0)
        {
            return 0;
        }
        int times=0;
        int res=0;
        for(int i=0;i<numbers.size();++i)
        {
            if(times==0)
            {
                res=numbers[i];
                ++times;
            }
            else if(res==numbers[i])
            {
                ++times;
            }
            else{
                --times;
            }
        }
        int cnt=0;
        for(int i=0;i<numbers.size();++i)
        {
            if(res==numbers[i])
            {
                ++cnt;
            }
        }
        if(cnt*2<=numbers.size())
        {
            return 0;
        }
        return res;
    }
};
