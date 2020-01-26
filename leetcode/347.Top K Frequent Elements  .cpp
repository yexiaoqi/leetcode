//自己的方法
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second>b.second;
}
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		vector<int> res;
		vector<pair<int, int>> vp;
		for (int i = 0; i<nums.size(); ++i)
		{
			++m[nums[i]];
		}
		for (auto a = m.begin(); a != m.end(); ++a)
		{
			vp.push_back(*a);//注意a是指针，要*a
		}
		sort(vp.begin(), vp.end(), compare);//sort无法直接对unordered_map排序
		for (int i = 0; i<k; ++i)
		{
			res.push_back(vp[i].first);
		}
		return res;
	}
};

//方法二
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second>b.second;
}
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		priority_queue<pair<int, int>> minheap;
		unordered_map<int, int> m;
		vector<int> res;
		//vector<pair<int,int>> vp;
		for (int i = 0; i<nums.size(); ++i)
		{
			++m[nums[i]];
		}
		for (auto a : m)
			//for(auto a=m.begin();a!=m.end();++a)
		{
			minheap.push(make_pair(a.second, a.first));
			//minheap.push(make_pair((*a).second,(*a).first));//priority_queue<pair<int,int>>按第一个int排序
			//vp.push_back(*a);
		}
		//sort(vp.begin(),vp.end(),compare);//sort无法直接对unordered_map排序
		for (int i = 0; i<k; ++i)
		{
			res.push_back(minheap.top().second);
			minheap.pop();
			//res.push_back(vp[i].first);
		}
		return res;
	}
};