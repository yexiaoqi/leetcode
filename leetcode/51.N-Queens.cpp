class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n,string(n,'.'));
        vector<vector<string>> res;
        int currow=0;
        helper(queens,res,currow);
        return res;
    }
    void helper(vector<string> &queens,vector<vector<string>> &res,int currow)
    {
        if(currow==queens.size())
        {
            res.push_back(queens);
            return;
        }
        for(int i=0;i<queens.size();++i)
        {
			/*queens[currow][i] = 'Q';
			if (isValid(currow, i, queens))
			{
				helper(queens, res, currow + 1);
			} 
			queens[currow][i] = '.';*///上下两行放括号内外都可以
            if(isValid(currow,i,queens))
            {
                queens[currow][i]='Q';
                helper(queens,res,currow+1);
                queens[currow][i]='.';
            }
        }
    }
    bool isValid(int row,int col,vector<string> &queens)
    {
        for(int i=0;i<row;++i)
        {
            if(queens[i][col]=='Q')
            {
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j)
        {
            if(queens[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0&&j<queens.size();--i,++j)
        {
            if(queens[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
};