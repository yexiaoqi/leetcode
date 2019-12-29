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