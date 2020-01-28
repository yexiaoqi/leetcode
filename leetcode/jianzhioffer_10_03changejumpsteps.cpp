//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
	int jumpFloorII(int n) {
		int res = 1 << (n - 1);
		return res;
	}
};

//复习，简单
class Solution {
public:
	int jumpFloorII(int n) {
		return pow(2, n - 1);
	}
};