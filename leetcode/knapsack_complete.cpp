//f[i][v]=max{f[i-1][v],f[i][v-c[i]]+w[i]}
//��N����Ʒ��һ������ΪV�ı�����ÿ����Ʒ�������޼����á���i����Ʒ�ķ�����c[i]����ֵ��w[i]
//f[i][v]=max{f[i-1][v],f[i][v-c[i]]+w[i]}
//��N����Ʒ��һ������ΪV�ı�����ÿ����Ʒ�������޼����á���i����Ʒ�ķ�����c[i]����ֵ��w[i]
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int capacity, products_count;
int worth[N], volume[N];
int res[N];

int main()
{
	cin >> products_count >> capacity;
	for (int i = 1; i <= products_count; ++i)
	{
		cin >> volume[i] >> worth[i];
	}

	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = volume[i]; j <= capacity; ++j)//����һֱѡ��i����ֱ������ﵽcapacity
		{
			res[j] = max(res[j], res[j - volume[i]] + worth[i]);
			//res[j]��û�ٴ�ѡ��i����res[j - volume[i]] + worth[i]���ٴ�ѡ�˵�i��

		}
	}
	cout << res[capacity];
	return 0;

}


int knapsack(int products_count, int capacity, vector<int>& volume,
	vector<int>& worth, vector<int>& result)
{
	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = volume[i]; j <= capacity; ++j)
		{
			res[j] = max(res[j], res[j - volume[i]] + worth[i]);
		}
	}
	return res[capacity];
}