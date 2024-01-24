#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 나이차이
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, age; // N, age
	vector<int> ages; // ages
	int min = 100, max = 2; // minAge, maxAge
	int result = 0; // result

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> age;
		ages.push_back(age);
	}

	for (int i = 0; i < n; i++) // min, max
	{
		if (min > ages.at(i))
		{
			min = ages.at(i);
		}

		if (max < ages.at(i))
		{
			max = ages.at(i);
		}
	}

	result = max - min;

	cout << result << "\n";
	return 0;
}