//ͬleetcode796
//ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(n��
class Solution {
public:
	//���� A + A ���������п���ͨ����ת������ A �õ����ַ������������ֻ��Ҫ�ж� B �Ƿ�Ϊ A + A ���Ӵ����ɡ�
	bool rotateString(string A, string B) {
		return A.size() == B.size() && (A + A).find(B) != string::npos;
	}
};