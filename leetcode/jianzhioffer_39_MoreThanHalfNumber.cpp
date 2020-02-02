//ͬleetcode169
//�Լ�д�ģ�O��n��ʱ�临�Ӷȣ�o��n���ռ临�Ӷ�
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


//����1��O��n��ʱ�临�Ӷȣ�o��1���ռ临�Ӷȣ�
//��Ϊֻѡһ�룬����ʱ�临�Ӷ���O(n��+O(n/2��+O(n/4��+...,��O(n�����Ӷ�
//���ţ�����O(n��+2O(n/2��+4O(n/4��+...,��O(nlogn�����Ӷ�

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
//��������O��n��ʱ�临�Ӷȣ�o��1���ռ临�Ӷ�
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



//��ϰ���Լ�����
bool g_Invalid = false;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int res = nums[0];
		int cnt = 1;
		for (int i = 1; i<nums.size(); ++i)
		{
			if (nums[i] == res)
			{
				++cnt;
			}
			else
			{
				--cnt;
				if (cnt == 0)
				{
					res = nums[i];
					cnt = 1;
				}
			}
		}
		int cntres = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] == res)
			{
				++cntres;
			}
		}
		if (cntres>nums.size() / 2)
		{
			return res;
		}
		g_Invalid = true;
		return 0;
	}
};