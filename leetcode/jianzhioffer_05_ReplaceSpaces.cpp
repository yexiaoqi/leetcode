/* ��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int orilen = 0;
		int numblank = 0;
		for (int i = 0; i<strlen(str); ++i)
		{
			++orilen;
			if (str[i] == ' ')
			{
				++numblank;
			}
		}
		int newlen = orilen + 2 * numblank;
		int oriptr = orilen;//ע��Ҫ���ƽ�����'\0'�����Ա�strlen(str)Ҫ��1
		int newptr = newlen;
		while (oriptr >= 0)
		{
			if (str[oriptr] == ' ')
			{
				str[newptr--] = '0';//i++����ԭ����ֵ��++i ���ؼ�1���ֵ��
				str[newptr--] = '2';
				str[newptr--] = '%';
			}
			else {
				str[newptr--] = str[oriptr];
			}
			--oriptr;
		}

	}
};