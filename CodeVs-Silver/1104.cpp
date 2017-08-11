#include <iostream>
#include <string>
using namespace std;
struct Result
{
	string name;
	int scholarship;
	int sum;
};
struct Student
{
	string name;
	int score1, score2;
	char leader;
	char west;
	int paper;
};
int main()
{
	int n; cin >> n;
	Result result{ "", 0, 0 };
	Student student;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> student.name >> student.score1 >> student.score2 >> student.leader >> student.west >> student.paper;
		temp = 0;
		if (student.score1 > 80 && student.paper >= 1) temp += 8000;
		if (student.score1 > 85 && student.score2 > 80) temp += 4000;
		if (student.score1 > 90) temp += 2000;
		if (student.score1 > 85 && student.west == 'Y') temp += 1000;
		if (student.score2 > 80 && student.leader == 'Y') temp += 850;
		result.sum += temp;
		if (temp > result.scholarship)
		{
			result.name = student.name;
			result.scholarship = temp;
		}
	}
	cout << result.name << endl << result.scholarship << endl << result.sum << endl;
	return 0;
}