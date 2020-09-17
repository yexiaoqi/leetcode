
//����splice
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
		// ���� (key, value) �� cache �е�λ��
		m[key] = l.begin();
		return kv.second; // value
						  // l.splice(l.begin(), l, it->second);//��it->second���е�l��l.begin()λ��
						  // return it->second->second;//it��m��ָ�룬it->secondָ��list<pair<int, int>>::iterator>��it->second->secondָ��list<pair<int, int>>::iterator>�ĵڶ���intҲ����value
	}

	void put(int key, int value) 
	{
		auto it = m.find(key);//�����л����в��Ҽ���put����Կ�Ƿ��Ѿ����ڹ�
		if (it != m.end()) l.erase(it->second);//����Ѿ��������keyɾ�����keyvalue��ɾ����it->secondָ��list<pair<int, int>>::iterator>
		l.push_front(make_pair(key, value));//���ڶ�������������
		m[key] = l.begin();//������������keyvalue��ӳ��
		if (m.size() > cap) //��������˻����С
		{
			int k = l.rbegin()->first;//list��firstҲ��m��first
			l.pop_back();//ɾȥ�ײ���
			m.erase(k);//��ɾȥ������ӳ��
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
		l.splice(l.begin(), l, it->second);//��it->second���е�l��l.begin()λ��
		return it->second->second;//it��m��ָ�룬it->secondָ��list<pair<int, int>>::iterator>��it->second->secondָ��list<pair<int, int>>::iterator>�ĵڶ���intҲ����value
	}

	void put(int key, int value) {
		auto it = m.find(key);//�����л����в��Ҽ���put����Կ�Ƿ��Ѿ����ڹ�
		if (it != m.end()) l.erase(it->second);//����Ѿ��������keyɾ�����keyvalue��ɾ����it->secondָ��list<pair<int, int>>::iterator>
		l.push_front(make_pair(key, value));//���ڶ�������������
		m[key] = l.begin();//������������keyvalue��ӳ��
		if (m.size() > cap) //��������˻����С
		{
			int k = l.rbegin()->first;//list��firstҲ��m��first
			l.pop_back();//ɾȥ�ײ���
			m.erase(k);//��ɾȥ������ӳ��
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

//�Լ�дһ��
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


//��ϰ
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