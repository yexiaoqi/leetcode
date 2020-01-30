void selectsort(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		int min = i;
		for (int j = i; j < arr.size(); ++j)
		{
			if (arr[min] >arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(arr[i], arr[min]);
		}
	}
}