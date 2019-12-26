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

//只是把上面的char改为string，结果对，但内存超了，这是为啥
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
        int numother=0;
        numother=first*(len-1)*pow(10,len-2);
        int numrecur=0;
         numrecur=numberof1(str);
        return numfirst+numother+numrecur;
    }
};
