#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ��������
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int num; // ����
	vector<int> insertVec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		insertVec[i] = num;
	}

	// ��������
	// 1~n-1 ���� ���鼭 ���� ���� �ε��� ����� ���� ���� ��ġ ã��
	// ���� �� ���
	// ���� �ε��� - 1 ���� ���� �ε��� ���� ��Ҹ� ���ʷ� ���������� ����Ʈ
	// ���� ������ġ�� ����
	// 11 7 5 6 10 9
	for (int i = 1; i < n; i++) // 1~n-1
	{
		int insertIndex = i; // ���� �� �ε���
		int backUpValue = insertVec[i];// ���� �� ���

		// ���� ��ġ ã��
		for (int j = i - 1; j > -1; j--)
		{
			if (insertVec[i] < insertVec[j])
			{
				insertIndex = j;
			}
		}

		// ���� ��ġ ���� ��� ������ ����Ʈ
		for (int j = i - 1; j > insertIndex - 1; j--)
		{
			insertVec[j + 1] = insertVec[j];
		}

		// ���� ���� ��ġ�� ����
		insertVec[insertIndex] = backUpValue;
	}

	for (int i = 0; i < n; i++)
	{
		cout << insertVec[i] << ' ';
	}

	return 0;
}