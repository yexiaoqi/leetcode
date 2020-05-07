//同leetcode796
//时间复杂度O(n^2),空间复杂度O(n）
class Solution {
public:
	//由于 A + A 包含了所有可以通过旋转操作从 A 得到的字符串，因此我们只需要判断 B 是否为 A + A 的子串即可。
	bool rotateString(string A, string B) {
		return A.size() == B.size() && (A + A).find(B) != string::npos;
	}
};