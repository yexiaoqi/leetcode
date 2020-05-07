//试图做，但不对



struct Uses
{
	int func;
	int size;
	vector<int> ituses;
	Uses() :func(0), size(0) {}
	Uses(int _func, int _size) :func(_func), size(_size) {}
};
void DFS(vector<Uses> &us, int &tmpres, int &res, int pos)
{
	if (us[pos].ituses.size() == 0)
	{
		if (res<tmpres)
		{
			res = tmpres;
		}
		return;
	}
	for (int i = 0; i<us[pos].ituses.size(); ++i)
	{
		//tmpres += us[i].ituses.size();
		//tmpres += us[pos].ituses[i].size();
		tmpres += us[us[pos].ituses[i]].size;
		DFS(us, tmpres, res, i);
		tmpres -= us[us[pos].ituses[i]].size;
		//tmpres -= us[i].ituses.size();
	}
}
int main()
{
	int n;
	cin >> n;

	vector<int> times(n, 0);
	for (int i = 0; i<n; ++i)
	{
		cin >> times[i];
	}
	vector<Uses> us(n);
	for (int i = 0; i<n; ++i)
	{

		if (cin.eof())
		{
			cout << "NA" << endl;
			return 0;
		}
		cin >> us[i].func >> us[i].size;
		if (us[i].func != i + 1 || (us[i].size <= 0))
		{
			cout << "NA" << endl;
			return 0;
		}
		for (int j = 0; j < times[i]; ++j)
		{
			//string tmp;
			int tmp = 0;
			cin >> tmp;
			//if (tmp == "")
			if (tmp == 0)
				//if (cin.eof())
			{
				cout << "NA" << endl;
				return 0;
			}
			//us[i].ituses.push_back(stoi(tmp));
			us[i].ituses.push_back(tmp);
		}
	}
	int res = 0;
	int pos = 0;
	int tmpres = 0;
	DFS(us, tmpres, res, 0);
	cout << "R" << endl;
	return 0;
}



