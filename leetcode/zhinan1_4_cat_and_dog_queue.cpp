//同leetcode 面试题 03.06. 动物收容所
class AnimalShelf {
public:
	AnimalShelf() {

	}

	void enqueue(vector<int> animal) {
		if (animal[1] == 0)
		{
			cat.push(animal);
		}
		else
		{
			dog.push(animal);
		}
	}

	vector<int> dequeueAny() {
		vector<int> animal;
		if (dog.empty() && cat.empty())
		{
			return vector<int>{-1, -1};
		}
		else if (dog.empty() && !cat.empty())
		{
			animal = cat.front();
			cat.pop();
		}
		else if (!dog.empty() && cat.empty())
		{
			animal = dog.front();
			dog.pop();
		}
		else if (dog.front()[0]<cat.front()[0])
		{
			animal = dog.front();
			dog.pop();
		}
		else
		{
			animal = cat.front();
			cat.pop();
		}
		return animal;
	}

	vector<int> dequeueDog() {
		vector<int> animal;
		if (dog.empty())
		{
			return vector<int>{-1, -1};
		}
		animal = dog.front();
		dog.pop();
		return animal;
	}

	vector<int> dequeueCat() {
		vector<int> animal;
		if (cat.empty())
		{
			return vector<int>{-1, -1};
		}
		animal = cat.front();
		cat.pop();
		return animal;
	}
private:
	queue<vector<int>> cat;
	queue<vector<int>> dog;
};

/**
* Your AnimalShelf object will be instantiated and called as such:
* AnimalShelf* obj = new AnimalShelf();
* obj->enqueue(animal);
* vector<int> param_2 = obj->dequeueAny();
* vector<int> param_3 = obj->dequeueDog();
* vector<int> param_4 = obj->dequeueCat();
*/