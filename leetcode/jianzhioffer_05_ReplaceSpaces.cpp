/* 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/
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
		int oriptr = orilen;//注意要复制结束符'\0'，所以比strlen(str)要多1
		int newptr = newlen;
		while (oriptr >= 0)
		{
			if (str[oriptr] == ' ')
			{
				str[newptr--] = '0';//i++返回原来的值，++i 返回加1后的值。
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