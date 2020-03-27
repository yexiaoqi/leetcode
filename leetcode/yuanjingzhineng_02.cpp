//用一维数组存储学号和成绩，按成绩排序输出
//我宝宝的代码
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
struct Student
{
	int id;
	int val;

	Student(int id, int val) :id(id), val(val)
	{
	}
	bool operator <(const Student & student) const
	{
		if (val < student.val) {
			return true;
		}
		return val == student.val && id < student.id;
	}
};

struct StudentComparator
{
	bool operator ()(const Student & s1, const Student & s2)
	{
		return s1 < s2;
	}
};

int main() {
	std::list<Student> students;
	int n;
	cin >> n;
	while (n--) 
	{
		int id, val;
		cin >> id >> val;
		students.push_back(Student(id, val));
	}
	students.sort(StudentComparator());
	for (Student & student : students)
		std::cout << student.id << " " << student.val << std::endl;
	return 0;
}

//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Score
{
	int id;
	int score;
};
bool cmp(Score s1, Score s2)
{
	if (s1.score != s2.score) return s1.score < s2.score;
	return s1.id < s2.id;
}
int main()
{
	vector<Score> student;
	int num;
	cin >> num;
	int id, score;
	while (num--)
	{
		cin >> id >> score;
		Score temp;
		temp.id = id;
		temp.score = score;
		student.push_back(temp);
	}
	sort(student.begin(), student.end(), cmp);
	for (int i = 0; i < student.size(); i++)
	{
		cout << student[i].id << " " << student[i].score << endl;
	}
	return 0;
}