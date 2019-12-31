//方法一
class assist {
public:
	assist()
	{
		++N;
		Sum += N;
	}
	static void reset()
	{
		N = 0;
		Sum = 0;
	}
	static int GetSum()
	{
		return Sum;
	}
private:
	static int N;
	static int Sum;
};
int assist::N = 0;
int assist::Sum = 0;
class Solution {
public:
	int Sum_Solution(int n) {
		assist::reset();
		assist *p = new assist[n];
		delete[]p;
		p = NULL;
		return assist::GetSum();
	}
};

//方法二
class A {
public:
	virtual int sum(int n)
	{
		return 0;
	}
};
A* arr[2];
class B :public A {
public:
	virtual int sum(int n)
	{
		return arr[!!n]->sum(n - 1) + n;
	}
};
class Solution {
public:
	int Sum_Solution(int n) {
		A a;
		B b;
		arr[0] = &a;
		arr[1] = &b;
		return arr[1]->sum(n);
	}
};


//方法三
class Solution {
public:
	int Sum_Solution(int n) {
		int sum = n;
		n && (sum += Sum_Solution(n - 1));
		return sum;
	}
};