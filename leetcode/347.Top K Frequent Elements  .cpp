//�Լ��ķ���
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
			vp.push_back(*a);//ע��a��ָ�룬Ҫ*a
		}
		sort(vp.begin(), vp.end(), compare);//sort�޷�ֱ�Ӷ�unordered_map����
		for (int i = 0; i<k; ++i)
		{
			res.push_back(vp[i].first);
		}
		return res;
	}
};

//������
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
			//minheap.push(make_pair((*a).second,(*a).first));//priority_queue<pair<int,int>>����һ��int����
			//vp.push_back(*a);
		}
		//sort(vp.begin(),vp.end(),compare);//sort�޷�ֱ�Ӷ�unordered_map����
		for (int i = 0; i<k; ++i)
		{
			res.push_back(minheap.top().second);
			minheap.pop();
			//res.push_back(vp[i].first);
		}
		return res;
	}
};