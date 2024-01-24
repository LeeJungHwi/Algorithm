#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Special Sort(구글)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // 숫자
	vector<int> plusVec; // 양의 정수 저장
	vector<int> minusVec; // 음의 정수 저장

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (num < 0)
		{
			minusVec.push_back(num);
			continue;
		}

		plusVec.push_back(num);
	}

	for (int i = 0; i < minusVec.size(); i++)
	{
		cout << minusVec[i] << ' ';
	}

	for (int i = 0; i < plusVec.size(); i++)
	{
		cout << plusVec[i] << ' ';
	}

	return 0;
}