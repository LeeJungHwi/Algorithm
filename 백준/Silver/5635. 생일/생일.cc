#include <bits/stdc++.h>
using namespace std;

#define home 0
#define loop(v, s, e) for(int v = s; v < e; v++)
#define elprint(a) cout << a << '\n'

struct Student
{
	string name;
	int year;
	int month;
	int day;

	Student() {}

	bool operator<(const Student &student)const
	{
		if (year != student.year) return year > student.year;
		if (month != student.month) return month > student.month;
		return day > student.day;
	}
};

// 생일
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	//ifstream cin;
	//cin.open("input.txt");

	int n;
	cin >> n;
	cin.ignore();

	vector<Student> ans;
	string inputString;
	loop(i, 0, n)
	{
		getline(cin, inputString);
		inputString += ' ';
		string temp = "";
		Student student = Student();
		int cur = 0;
		loop(j, 0, inputString.size())
		{
			if (inputString[j] == ' ')
			{
				if (cur == 0) student.name = temp;
				else if (cur == 1) student.day = stoi(temp);
				else if (cur == 2) student.month = stoi(temp);
				else if (cur == 3) student.year = stoi(temp);

				temp.clear();
				cur++;
				continue;
			}

			temp += inputString[j];
		}

		ans.push_back(student);
	}

	sort(ans.begin(), ans.end());

	elprint(ans.front().name);
	if (n > 1) elprint(ans.back().name);

	return home;
}