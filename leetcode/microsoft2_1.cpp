//x只能通过减一和 * 2进行变换y，给定x和y，求x变成y的最短步数


//X = 2, Y = 3
//* 2, -1
//
//2 * 2 = 4
//4 - 1 = 3
//
//2 - 1 = 1
//1 * 2 = 2
//2 * 2 = 4
//4 - 1 = 3
//
//X = 2, Y = 5
//
//
//Y->X
/// 2, +1
//
//

//从x变成y，无法判断先进行减1还是乘2操作，因为乘2快，但是乘2可能会超过y，减去1的次数就变多了，但是
//又不知道先减几次，那么我们去想去减几次呢？应该减到y的一半再去乘2最快，所以我们就想到了倒着做，把
//y变成x，那么对y只要先不断进行除以2的操作（碰到奇数要加1），一直除到变成比x小的第一个数z，此时我们
//再加上x和z之间的差值即可
class Solution
{
public:
	int minstep(int x, int y)
	{
		int step = 0;
		while (y>x)
		{
			if (y & 0x1)
			{
				++y;
				++step;
			}
			y /= 2;
			++step;
		}
		step = x - y + step;
		return step;
	}
};