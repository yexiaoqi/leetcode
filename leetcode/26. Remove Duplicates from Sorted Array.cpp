//Given a sorted array, remove the duplicates in-place such that each element appear
//only once and return the new length.

//Do not allocate extra space for another array, you must do this by modifying the
//input array in - place with O(1) extra memory.

//sulution1
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty())return 0;
		/*���߿��� 
		if (nums.size()<=1)
        {
            return nums.size();
        }*/
		int index = 0;
		for (int i = 1;i<nums.size();++i)
		{
			if (nums[index] != nums[i])
			{
				/*i++ �� ++i ����Ҫ������������
1�� i++ ����ԭ����ֵ��++i ���ؼ�1���ֵ��
2�� i++ ������Ϊ��ֵ����++i ���ԡ�*/
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};

//solution 2
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		// distance��Ҫ������������������֮���Ԫ�ظ���
		//�ú����������ǡ�ȥ����������������������Ԫ�ص��ظ����ֵ�Ԫ��,�����ȥ���������������erase�����ǽ��ظ���Ԫ�طŵ�������ĩβ������ֵ��ȥ��֮���β��ַ��
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}
};