class TrieNode
{
public:
	TrieNode *child[26];//字母的字典树每个节点要定义一个大小为 26 的子节点指针数组
	bool isword;//用以区分是前缀还是就是这个单词,用一个标志符用来记录到当前位置为止是否为一个词
	TrieNode() :isword(false)
	{
		for (int i = 0; i<26; ++i)
		{
			child[i] = NULL;//始化的时候讲 26 个子节点都赋为空
		}
		// for(auto &a:child)//注意a之前要加&，不能是*（auto会退化成指向数组的指针，除非被声明为引用）
		// {
		//     a=NULL;
		// }

	}
};
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		node = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) 
// insert 操作只需要对于要插入的字符串的每一个字符算出其的位置，然后找是否存在这个子节点，若不存在则新建一个，
//然后再查找下一个
	{
		TrieNode *p = node;
		for (int i = 0; i<word.size(); ++i)
		{
			//int i=word[i]-'a';
			int j = word[i] - 'a';
			if (!p->child[j])
			{
				p->child[j] = new TrieNode();
			}
			p = p->child[j];
		}
		p->isword = true;
	}

	/** Returns if the word is in the trie. */
//查找词和找前缀操作跟 insert 操作都很类似，不同点在于若不存在子节点，则返回 false
	bool search(string word) {
		TrieNode *p = node;
		for (int i = 0; i<word.size(); ++i)
		{
			//int i=word[i]-'a';
			int j = word[i] - 'a';
			if (!p->child[j])
			{
				return false;
			}
			p = p->child[j];
		}
		return p->isword;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *p = node;
		for (int i = 0; i<prefix.size(); ++i)
		{
			//int i=word[i]-'a';
			int j = prefix[i] - 'a';
			if (!p->child[j])
			{
				return false;
			}
			p = p->child[j];
		}
		return true;
	}
private:
	TrieNode *node;
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/


//复习
class TrieNode
{
public:
	bool isWord;
	TrieNode *child[26];
	TrieNode() :isWord(false)
	{
		for (int i = 0; i<26; ++i)
		{
			child[i] = NULL;
		}
	}
};
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		node = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = node;
		for (int i = 0; i<word.size(); ++i)
		{
			int j = word[i] - 'a';
			if (!p->child[j])
			{
				p->child[j] = new TrieNode();
			}
			p = p->child[j];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *p = node;
		for (int i = 0; i<word.size(); ++i)
		{
			int j = word[i] - 'a';
			if (!p->child[j])
			{
				return false;
			}
			p = p->child[j];
		}
		return p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *p = node;
		for (int i = 0; i<prefix.size(); ++i)
		{
			int j = prefix[i] - 'a';
			if (!p->child[j])
			{
				return false;
			}
			p = p->child[j];
		}
		return true;
	}
private:
	TrieNode *node;
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/