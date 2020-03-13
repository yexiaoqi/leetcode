//同leetcode151
class Solution {
public:
    void reverse(string &str,int begin,int end)
    {
       while(begin<end)
       {
           
		   swap(str[begin++],str[end--]);
       }
    }
    string ReverseSentence(string str) {
       int begin=0;
        int end=str.size()-1;
        reverse(str,begin,end);
        int i=0;
        while(i<=end)
        {
            while(i<=end&&str[i]==' ')
            {
                i++;
            }
            int b=i;
            int e=i;
            while(i<=end&&str[i]!=' ')
            {
                i++;
                e++;
            }
            reverse(str,b,e-1);
        }
        return str;
    }
};
