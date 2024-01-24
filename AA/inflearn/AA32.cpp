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

	vector<int> unsortedVec(n); // ���ĵ��� ���� ����
	vector<int> sortedVec(n); // ���ĵ� ����

	// ���ĵ��� ���� ���� ����
	for (int i = 0; i < unsortedVec.size(); i++)
	{
		cin >> num;
		unsortedVec[i] = num;
	}

	// ��������
	// ��� 6�� ����
	// 6 -> 5 -> 4 -> ... -> 1
	// n - 0 -> n-1 -> ... -> 1
	// ���ĵ��� ���� �������� �ִ밪 ã��
	// ã�� �ִ� ���� �ε����� ���ĵ��� ���� ������ ������ �� ��Ҹ� ����
	// ã�� �ִ� ���� ���ĵ� ������ ������ ���� ����

	for (int i = 0; i < n; i++)
	{
		int max = 0; // �ִ밪
		int maxIndex = 0; // �ִ밪�� �ε���

		for (int j = 0; j < n - i; j++) // n - 0 -> n-1 -> ... -> 1
		{
			if (unsortedVec[j] > max) // max ����
			{
				max = unsortedVec[j];
				maxIndex = j;
			}
		}

		// �ִ밪 ���� ����
		unsortedVec[maxIndex] = unsortedVec[n - i - 1]; // ã�� �ִ� ���� �ε����� ���ĵ��� ���� ������ ������ �� ��Ҹ� ����
		sortedVec[n - i - 1] = max; // ã�� �ִ� ���� ���ĵ� ������ ������ ���� ����
	}

	for (int i = 0; i < n; i++)
	{
		cout << sortedVec[i] << ' ';
	}

	return 0;
}