class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length <= 0)
		{
			return false;
		}
		for (int i = 0; i<length; ++i)
		{
			if (numbers[i]<0 || numbers[i] >= length)
			{
				return false;
			}
		}
		for (int i = 0; i<length; ++i)
		{
			while (numbers[i] != i)//注意这行
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				else
				{
					swap(numbers[i], numbers[numbers[i]]);
				}
			}
		}
		return false;
	}
};


//复习
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int nums[], int length, int* duplication) {
		if (nums == NULL || length <= 0)
		{
			return false;
		}
		for (int i = 0; i<length; ++i)
		{
			if (nums[i]<0 || nums[i]>length - 1)
			{
				return false;
			}
		}
		for (int i = 0; i<length; ++i)
		{
			/*if(nums[i]!=i&&nums[i]==nums[nums[i]])
			{
			*duplication=nums[i];
			return true;
			}
			while(nums[i]!=i)
			{
			swap(nums[i],nums[nums[i]]);
			}*/
			/*上面这样不对，第一次没有进入if(nums[i]!=i&&nums[i]==nums[nums[i]])以后，
			就会一直执行 while(nums[i]!=i)，无法再去判断if(nums[i]!=i&&nums[i]==nums[nums[i]])
			满不满足了
			*/
			while (nums[i] != i)
			{
				if (nums[i] == nums[nums[i]])
				{
					*duplication = nums[i];
					return true;
				}
				else
				{
					swap(nums[i], nums[nums[i]]);
				}
			}

		}
		return false;
	}
};