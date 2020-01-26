//自己做出，一遍ac
class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.empty())
		{
			return;
		}
		int begin = 0, end = s.size() - 1;
		while (begin<end)
		{
			swap(s[begin++], s[end--]);
		}
	}
};