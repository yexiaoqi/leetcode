//O(n^2)
//建立个一维数组用来标记每个人的名人候选状态，开始均初始化为 true，表示每个人都是名人候选人，
//然后我们一个人一个人的验证其是否为名人，对于候选者i，我们遍历所有其他人j，如果i认识j，或者j不认识i
//，说明i不可能是名人，那么我们标记其为 false，然后验证下一个候选者，反之如果i不认识j，或者j认识i，
//说明j不可能是名人，标记之。对于每个候选者i，如果遍历了一圈而其候选者状态仍为 true，说明i就是名人，返回即可，
//如果遍历完所有人没有找到名人，返回 - 1
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		vector<bool> people(n, true);
		for (int i = 0; i<n; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				if (people[i] && i != j)
				{
					if (knows(i, j) || !knows(j, i))
					{
						people[i] = false;
						break;
					}
					else
					{
						people[j] = false;
					}
				}
			}
			if (people[i])
			{
				return i;
			}
		}
		return -1;
	}
};


//O(n)
//设定候选人 res 为0，原理是先遍历一遍，对于遍历到的人i，若候选人 res 认识i，则将候选人 res 设为i，
//完成一遍遍历后，我们来检测候选人 res 是否真正是名人，我们如果判断不是名人，则返回 - 1，如果并没有冲突，
//返回 res
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		int res = 0;
		for (int i = 1; i<n; ++i)
		{
			if (knows(res, i))
			{
				res = i;
			}
		}
		for (int i = 0; i<n; ++i)
		{
			if (res != i && (knows(res, i) || !knows(i, res)))
			{
				return -1;
			}
		}
		return res;
	}
};


//更快的解法
//还可以进一步减少 API 的调用量，找候选者的方法跟上面相同，但是在验证的时候，分为两段，先验证候选者前面的所有人，
//若候选者认识任何人，或者任何人不认识候选者，直接返回 - 1。再验证候选者后面的人，
//这时候只需要验证是否有人不认识候选者就可以了，
//因为我们在最开始找候选者的时候就已经保证了候选者不会认识后面的任何人
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		int res = 0;
		for (int i = 1; i<n; ++i)
		{
			if (knows(res, i))
			{
				res = i;
			}
		}
		for (int i = 0; i<res; ++i)
		{
			if (knows(res, i) || !knows(i, res))
			{
				return -1;
			}
		}
		for (int i = res + 1; i<n; ++i)
		{
			if (!knows(i, res))
			{
				return -1;
			}
		}
		return res;
	}
};