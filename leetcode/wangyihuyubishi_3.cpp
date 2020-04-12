//不会，可能是从图的方向去做
struct Point
{
	int x;
	int y;
	Point() :x(0), y(0) {}
	Point(int _x, int _y) :x(_x), y(_y) {}
};
int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<char>> gamers(N + 1, vector<char>(M + 1));
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> gamers[i][j];
		}
	}
	unordered_map<Point, vector<Point>> playwith;
	unordered_map<Point, vector<Point>> notplaywith;
	while (true)
	{
		Point tmp1;
		Point tmp2;
		cin >> tmp1.x >> tmp1.y;
		char flag;
		cin >> flag;
		cin >> tmp2.x >> tmp2.y;
		if (flag == 'Y')
		{
			playwith[tmp1].push_back(tmp2);
		}
		else
		{
			notplaywith[tmp1].push_back(tmp2);
		}
	}
	for (auto a = playwith.begin(); a != playwith.end(); ++a)
	{
		for (int i = 0; i < (*a).second.size(); ++i)
		{
			/*for (int j = 0; j < playwith[(*a).second[i]].second.size(); ++j)
			{
			playwith[(*a).first].push_back(playwith[(*a).second[i]].second);
			}*/

		}
	}
	return 0;
}

