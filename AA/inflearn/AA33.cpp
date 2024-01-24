#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 3���� ������?
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

	// 3�� �ε��� ���ϱ�
	// 75 80 82 92 96 96 100
	// ���ĵ� ���� ������ �����ϸ鼭 �������� �ٸ��� 3���ε��� ++
	// 3���ε����� 3�ΰ��� ���� 3���� ����
	int thirdIndex = 0;
	int preScore = -1;
	for (int i = sortedVec.size() - 1; i > -1; i--)
	{
		if (sortedVec[i] != preScore)
		{
			preScore = sortedVec[i];
			thirdIndex++;

			if (thirdIndex == 3)
			{
				break;
			}
		}
	}

	cout << preScore << '\n';

	return 0;
}