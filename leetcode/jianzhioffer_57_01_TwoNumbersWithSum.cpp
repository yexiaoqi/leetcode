//自己的方法，空间复杂度o(n),时间复杂度o(n)
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		unordered_map<int, int> mapping;
		vector<int> res;
		for (int i = 0; i<array.size(); ++i)
		{
			mapping[array[i]] = i;
		}
		for (int i = 0; i<array.size(); ++i)
		{
			int gap = sum - array[i];
			if (mapping.find(gap) != mapping.end())
			{
				res.push_back(array[i]);
				res.push_back(gap);
				return res;
			}
		}
		return res;
	}
};

//空间复杂度o(1),时间复杂度o(n)
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.size()<=1)
        {
            return res;
        }
        int begin=0;
        int end=array.size()-1;
        while(begin<end)
        {
            int sum2=array[begin]+array[end];
            if(sum2==sum)
            {
                res.push_back(array[begin]);
                res.push_back(array[end]);
                return res;
            }
            else if(sum2<sum)
            {
                ++begin;
            }
            else{
                --end;
            }
        }
        return res;
    }
};
