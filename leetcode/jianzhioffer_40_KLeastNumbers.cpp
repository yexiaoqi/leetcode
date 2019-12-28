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

//方法2，时间复杂度o(n)
class Solution {
public:
    int partition(vector<int> &nums,int begin,int end)//注意要有&
    {
        int key=nums[begin];
        while(begin<end)
        {
            while(begin<end&&nums[end]>=key)
            {
                --end;
            }
            nums[begin]=nums[end];
            while(begin<end&&nums[begin]<=key)
            {
                ++begin;
            }
            nums[end]=nums[begin];     
        }
        nums[begin]=key;
        return begin;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k<=0||input.size()<k)//注意k<=0的情况
        {
            return res;
        }
        int begin=0;
        int end=input.size()-1;
        int index=partition(input,begin,end);
        while(index!=(k-1))
        {
            if(index>(k-1))
            {
                end=index-1;
                index=partition(input,begin,end);
            }
            else
            {
                begin=index+1;
                
                index=partition(input,begin,end);
            }
        }
        for(int i=0;i<k;++i)
        {
            res.push_back(input[i]);
        }
        return res;
    }
};

//时间复杂度O（nlogk），适合处理海量数据
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k<=0||input.size()<k)//注意k<=0的情况
        {
            return res;
        }
        multiset<int,greater<int>> res_set;
        //i其实是vector<int>::iterator i=data.begin()
        for(auto i=input.begin();i!=input.end();++i)
        {
            if(res_set.size()<k)
            {
                res_set.insert(*i);//注意*,i是一个指针
            }
            else
            {
                if(*i<(*res_set.begin()))
                {
                    res_set.erase(res_set.begin());
                    res_set.insert(*i);
                }
            }
        }
        return vector<int>(res_set.begin(),res_set.end());
    }
};


//使用最大堆，应该也是O（nlogk）
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k<=0||input.size()<k)//注意k<=0的情况
        {
            return res;
        }
        priority_queue<int,vector<int>> q;
        for(auto i=input.begin();i!=input.end();++i)
        {
            if(q.size()<k)
            {
                q.push(*i);
            }
            else
            {
                if(*i<q.top())
                {
                    q.pop();
                    q.push(*i);
                }
            }
        }
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
