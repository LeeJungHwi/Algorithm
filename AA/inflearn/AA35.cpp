#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Special Sort(����)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // ����
	vector<int> plusVec; // ���� ���� ����
	vector<int> minusVec; // ���� ���� ����

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