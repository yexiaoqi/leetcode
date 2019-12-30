//方法一
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
        {
            return -1;
        }
        list<int> circle;/*如果需要高效的随机存取，而不在乎插入和删除的效率，使用vector;
如果需要大量的插入和删除，而不关心随机存取，则应使用list。*/
        
        for(int i=0;i<n;++i)
        {
            circle.push_back(i);
        }
        auto cur=circle.begin();//如果circle是数组，那么circle.begin()是int而不是指针
        while(circle.size()>1)
        {
            for(int i=0;i<m-1;++i)
            {
                cur++;
                if(cur==circle.end())
                {
                    cur=circle.begin();
                }
            }
            auto next=++cur;
            if(next==circle.end())
            {
                next=circle.begin();
            }
            --cur;
            circle.erase(cur);
            cur=next;
        }
        return *cur;
    }
};

//方法二
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
        {
            return -1;
        }
        int res=0;
        for(int i=2;i<=n;++i)
        {
            res=(res+m)%i;
        }
        return res;
    }
};
