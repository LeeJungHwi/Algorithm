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
	vector<int> bubbleVec(n); // ���� ���� �� ��� ����

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		bubbleVec[i] = num;
	}

	// ��������
	// 6 ���� ��
	// 5 -> 4 -> 3 -> 2 -> 1
	// �� ���ܿ��� ���� ��ҿ� ũ�� ���� ����
	// �� ���� �� �� ������ ������ �� ������ ���ĵ�

	int tempNum = 0; // ���ҿ�
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (bubbleVec[j] > bubbleVec[j + 1]) // ũ�� �� �� ����
			{
				tempNum = bubbleVec[j];
				bubbleVec[j] = bubbleVec[j + 1];
				bubbleVec[j + 1] = tempNum;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << bubbleVec[i] << ' ';
	}

	return 0;
}