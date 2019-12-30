class Solution {
public:
    void reverse(string &str,int begin,int end)//注意引用
    {
        while(begin<end)
        {
            swap(str[begin++],str[end--]);
        }
    }
    string LeftRotateString(string str, int n) {
        int begin=0;
        int end=str.size()-1;
        if(str.size()<=1)
        {
            return str;
        }
        n=n%str.size();
        reverse(str,0,n-1);
        reverse(str,n,end);
        reverse(str,begin,end);
        return str;
    }
};
