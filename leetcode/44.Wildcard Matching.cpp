//iStar �� jStar ����ʼ��Ϊ - 1����ʾĬ���������û���Ǻŵġ�
//Ȼ��������������i��j�ֱ�ָ��ǰs����p���б�������λ�á�

class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, istar = -1, jstar = -1, m = s.size(), n = p.size();
		while (i<m)//��ʼ����ƥ�䣬��iС��s���ĳ��ȣ����� while ѭ��
		{
			if (j<n && (p[j] == s[i] || p[j] == '?'))
			{
				++i, ++j;//����ǰ�����ַ���ȣ�����p�е��ַ����ʺţ���i��j�ֱ��1
			}
			else if (j<n&&p[j] == '*')//�� p[j] ���Ǻţ�Ҫ��¼�Ǻŵ�λ�ã�jStar ��Ϊj����ʱj������1��iStar ��Ϊi
			{
				istar = i;//iStar��ʾ�Ǻ�ƥ�䵽s���е�λ��,����˵ƥ�䵽����*�ܵ����λ�õĺ�һ��
				jstar = j;//jstar��p�����Ǻ�*��λ��
				++j;
			}
			//����ǰ p[j] �����Ǻţ����Ҳ��ܸ� p[i] ƥ���ϣ���ʱ��Ҫ���Ǻ��ˣ���֮ǰ�Ǻ�û���ֹ�����ô��ֱ�ӹ�;
			//����Ǻ�֮ǰ���ֹ�������ǿ����һ����
			////�������֪��֮ǰ��û���Ǻţ���ʱ���ܿ��� iStar �������ˣ���Ϊ���ʼ��Ϊ - 1��
			//�������Ǻ�ʱ����ͻᱻ����Ϊi��ֻҪ��� iStar ��ֵ������֪���Ƿ����ʹ���Ǻ�������
			else if (istar >= 0)
			{
				i = istar;
				++istar;
				j = jstar + 1;
			}
			else
			{
				return false;
			}
		}
//��Ȼ�ɹ���������ƥ������s�е������ַ�������֮��Ҫ���p������ʱûƥ�����p����ֻ��ʣ�Ǻţ��������������ַ������������ǺŹ��˵������j������p�ĳ��ȣ��򷵻� false
		while (j<n&&p[j] == '*')
		{
			++j;
		}
		return j == n;
	}
};


//��ϰ
class Solution {
public:
	bool isMatch(string s, string p) {
		int istar = -1, jstar = -1, m = s.size(), n = p.size(), i = 0, j = 0;
		while (i<m)
		{
			if (j<n && (p[j] == s[i] || p[j] == '?'))
			{
				++i;
				++j;
			}
			else if (j<n&&p[j] == '*')
			{
				istar = i;
				jstar = j;
				++j;
			}
			else if (istar >= 0)
			{
				i = istar;
				++istar;
				j = jstar + 1;
			}
			else
			{
				return false;
			}
		}
		while (j<n&&p[j] == '*')
		{
			++j;
		}
		return j == n;
	}
};