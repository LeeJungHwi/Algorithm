#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// ���湮��(����)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int jewelCnt; // �������� 4
	int bagWeight; // ���� �ִ���� ���� 11

	cin >> jewelCnt >> bagWeight;

	vector<pair<int, int> > jewels(jewelCnt); // ����
	vector<int> values(bagWeight + 1); // ������ ���Կ� ���� �������ִ� �ִ밡ġ ����

	int weight; // ���� ����
	int value; // ���� ��ġ

	//	5 12
	//	3 8
	//	6 14
	//	4 8
	for (int i = 0; i < jewelCnt; i++)
	{
		cin >> weight >> value;

		jewels[i] = { weight, value };
	}

	// ����������ŭ ���鼭 values ����
	for (int i = 0; i < jewelCnt; i++)
	{
		for (int j = jewels[i].first; j < bagWeight + 1; j++) // ���� ���� ~ ���� ���� ���� ���鼭 �ִ밡ġ ����
		{
			if (values[j] < values[j - jewels[i].first] + jewels[i].second)
			{
				values[j] = values[j - jewels[i].first] + jewels[i].second;
			}
		}
	}

	cout << values[bagWeight] << '\n';

	return 0;
}