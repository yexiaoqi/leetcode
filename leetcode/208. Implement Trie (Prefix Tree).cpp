class TrieNode
{
public:
	TrieNode *child[26];
	bool isword;//用以区分是前缀还是就是这个单词
	TrieNode() :isword(false)
	{
		for (int i = 0; i<26; ++i)
		{
			child[i] = NULL;
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
	void insert(string word) {
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