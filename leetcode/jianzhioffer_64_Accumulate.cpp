//方法一
class assist {
public:
	assist()
	{
		++N;
		Sum += N;
	}
	static void reset()//注意要有reset函数，否则只能调用一次
	{
		N = 0;
		Sum = 0;
	}
	static int GetSum()//注意声明为静态函数
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
		assist p[n];
		return assist::GetSum();
	}
};
//c语言版本
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



//复习
class assist
{
public:
	assist()
	{
		++N;
		SUM += N;
	}
	static void Reset()
	{
		N = 0;
		SUM = 0;
	}
	static int GetSum()
	{
		return SUM;
	}
private:
	static int N;
	static int SUM;
};
int assist::N = 0;
int assist::SUM = 0;
class Solution {
public:
	int Sum_Solution(int n) {
		assist::Reset();
		assist A[n];
		return assist::GetSum();
	}
};


class A
{
public:
	virtual int sum(int n)
	{
		return 0;
	}
};
A* arr[2];
class B :public A
{
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

class Solution {
public:
	int Sum_Solution(int n) {
		int sum = n;
		n && (sum += Sum_Solution(n - 1));
		return sum;
	}
};