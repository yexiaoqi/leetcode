class Solution
{
public:
	Solution()
	{
		memset(cnt, 0, sizeof(cnt));
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		++cnt[ch - '\0'];
		if (cnt[ch - '\0'] == 1)
		{
			data.push(ch);
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!data.empty() && cnt[data.front()] != 1)
		{
			data.pop();
		}
		if (data.empty())
		{
			return '#';
		}
		return data.front();
	}
private:
	queue<char> data;
	int cnt[128];
};