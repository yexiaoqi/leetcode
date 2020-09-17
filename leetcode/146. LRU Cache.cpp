
//不用splice
class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) 
	{
		auto it = m.find(key);
		if (it == m.end()) return -1;
		pair<int, int> kv = *m[key];
		l.erase(m[key]);
		l.push_front(kv);
		// 更新 (key, value) 在 cache 中的位置
		m[key] = l.begin();
		return kv.second; // value
						  // l.splice(l.begin(), l, it->second);//把it->second剪切到l的l.begin()位置
						  // return it->second->second;//it是m的指针，it->second指向list<pair<int, int>>::iterator>，it->second->second指向list<pair<int, int>>::iterator>的第二个int也就是value
	}

	void put(int key, int value) 
	{
		auto it = m.find(key);//早已有缓存中查找即将put的密钥是否已经存在过
		if (it != m.end()) l.erase(it->second);//如果已经存在这个key删掉此项（keyvalue都删），it->second指向list<pair<int, int>>::iterator>
		l.push_front(make_pair(key, value));//并在顶部插入新来项
		m[key] = l.begin();//建立与新来的keyvalue的映射
		if (m.size() > cap) //如果超出了缓存大小
		{
			int k = l.rbegin()->first;//list的first也是m的first
			l.pop_back();//删去底部项
			m.erase(k);//并删去建立的映射
		}
	}

private:
	int cap;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end()) return -1;
		l.splice(l.begin(), l, it->second);//把it->second剪切到l的l.begin()位置
		return it->second->second;//it是m的指针，it->second指向list<pair<int, int>>::iterator>，it->second->second指向list<pair<int, int>>::iterator>的第二个int也就是value
	}

	void put(int key, int value) {
		auto it = m.find(key);//在已有缓存中查找即将put的密钥是否已经存在过
		if (it != m.end()) l.erase(it->second);//如果已经存在这个key删掉此项（keyvalue都删），it->second指向list<pair<int, int>>::iterator>
		l.push_front(make_pair(key, value));//并在顶部插入新来项
		m[key] = l.begin();//建立与新来的keyvalue的映射
		if (m.size() > cap) //如果超出了缓存大小
		{
			int k = l.rbegin()->first;//list的first也是m的first
			l.pop_back();//删去底部项
			m.erase(k);//并删去建立的映射
		}
	}

private:
	int cap;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

//自己写一遍
class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end())
		{
			return -1;
		}
		l.splice(l.begin(), l, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto i = m.find(key);
		if (i != m.end())
		{
			l.erase(i->second);
		}
		l.push_front(make_pair(key, value));
		m[key] = l.begin();
		if (m.size()>cap)
		{
			m.erase(l.rbegin()->first);
			l.pop_back();
		}
	}

private:
	int cap;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/


//复习
class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key)
	{
		auto it = m.find(key);
		if (it == m.end())
		{
			return -1;
		}
		pair<int, int> kv = *m[key];
		l.erase(it->second);
		l.push_front(kv);
		m[key] = l.begin();
		return kv.second;
	}
	void put(int key, int value)
	{
		auto it = m.find(key);
		if (it != m.end())
		{
			l.erase(it->second);
		}
		l.push_front(make_pair(key, value));
		m[key] = l.begin();
		if (m.size()>cap)
		{
			int k = l.rbegin()->first;
			l.pop_back();
			m.erase(k);
		}
	}
private:
	int cap;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

//fuxi 
class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end())
		{
			return -1;
		}
		auto kv = *m[key];
		l.erase(m[key]);
		l.push_front(kv);
		m[key] = l.begin();
		return kv.second;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if (it != m.end())
		{
			l.erase(m[key]);
		}
		l.push_front(make_pair(key, value));
		m[key] = l.begin();
		if (m.size()>cap)
		{
			int k = l.rbegin()->first;
			l.pop_back();
			m.erase(k);
		}
	}
private:
	int cap;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
};