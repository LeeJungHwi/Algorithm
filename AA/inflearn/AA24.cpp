#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

// ���� ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> cntSubSequences(101, 0); // ������ �� ���� �� ī��Ʈ

	int num; // ����
	int preNum = 0; // ���� ����
	int subNum = 0; // ������ �� ���� ��

	// ó�� ���� ���� -> 0��
	cin >> num;
	preNum = num;

	for (int i = 1; i < n; i++) // -> 1 ~ n-1��
	{
		cin >> num;

		// ������ �� ���� �� ����
		subNum = abs(preNum - num);

		if (subNum > 0 && subNum < 101)
		{
			cntSubSequences[subNum]++;
		}

		// ���� ���� ����
		preNum = num;
	}

	// ������������ üũ
	// 4
	// -2 1 2 4
	// 3 1 2
	for (int i = 1; i < n; i++)
	{
		if (cntSubSequences[i] == 0) // �ϳ��� 0�̸� NO
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n"; // ��� ������ YES
	return 0;
}

// �ٽ�
// ���� ���� -> 1���� N-1 ���� ���� ������ �� ���� ���� ��� ��������