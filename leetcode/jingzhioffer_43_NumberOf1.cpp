class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        char str[50];
        sprintf(str,"%d",n);
        int res=numberof1(str);
        return res;
    }
    int numberof1(char str[])
    {
        if(!str||*str<'0'||*str>'9'||*str=='\0')
        {
            return 0;
        }
        int first=*str-'0';
        int numfirst=0;
        int len=strlen(str);
        if(len==1&&first==0)
        {
            return 0;
        }
        if(len==1&&first>=1)
        {
            return 1;
        }
        if(first>1)
        {
            numfirst=pow(10,len-1);
        }
        else if(first==1)
        {
            numfirst=atoi(str+1)+1;
        }
        int numother=0;
        numother=first*(len-1)*pow(10,len-2);
        int numrecur=0;
        numrecur=numberof1(str+1);
        return numfirst+numother+numrecur;
    }
};

//把上面的char改为string
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        string strs=to_string(n);
        return numberof1(strs);
    }
    int numberof1(string &str)
    {
        int first=str[0]-'0';
        int len=str.size();
        int numfirst=0;
        if(len==1&&first==0)
        {
            return 0;
        }
        if(len==1&&first>=1)
        {
            return 1;
        }
        if(first>1)
        {
            numfirst=pow(10,len-1);
             str.erase(0,1);
        }
        else if(first==1)
        {
            str.erase(0,1);
            numfirst=stoi(str)+1;
        }
		else
		{
			str.erase(0, 1);
		}//不要漏了first还可能为0，否则就出不去了
        int numother=0;
        numother=first*(len-1)*pow(10,len-2);
        int numrecur=0;
         numrecur=numberof1(str);
        return numfirst+numother+numrecur;
    }
};

//方法二https://www.nowcoder.com/profile/3371548/codeBookDetail?submissionId=16319486
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt=0;
        long long i=1;
        for(;i<=n;i*=10)
        {
            int a=n/i;
            int b=n%i;
            if(a%10==0)
            {
                cnt+=a/10*i;
            }
            else if(a%10==1)
            {
                cnt+=a/10*i+b+1;
            }
            else{
                cnt+=(a/10+1)*i;
            }
        }
        return cnt;
    }
   
};
