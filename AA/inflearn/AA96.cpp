#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �ִ� �� �����ϱ�(LIS)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<int> leftVec(n + 1); // ���� ��ȣ
	vector<int> rightVec(n + 1); // ������ ��ȣ
	vector<int> length(n + 1); // ������ ��ȣ ���� ����

	for (int i = 1; i < n + 1; i++)
	{
		leftVec[i] = i; // 1 2 3 4 5 6 7 8 9 10
		cin >> rightVec[i]; // 4 1 2 3 9 7 5 6 10 8
	}

	// rightVec �ε��� 1���� �����Ҷ� -> 4 -> 1��
	// rightVec �ε��� 2���� �����Ҷ� -> 1 -> 1��
	// rightVec �ε��� 3���� �����Ҷ� -> ������ 1 -> �ִ���� 1 + 1 -> 1 2 -> 2��
	// rightVec �ε��� 4���� �����Ҷ� -> ������ 2, 1 -> �ִ���� 2 + 1 -> 1 2 3 -> 3��
	// rightVec �ε��� 5���� �����Ҷ� -> ������ 3, 2, 1, 4 -> �ִ���� 3 + 1 -> 1 2 3 9 -> 4��
	// rightVec �ε��� 6���� �����Ҷ� -> ������ 3, 2, 1, 4 -> �ִ���� 3 + 1 -> 1 2 3 7 -> 4��
	// rightVec �ε��� 7���� �����Ҷ� -> ������ 3, 2, 1, 4 -> �ִ���� 3 + 1 -> 1 2 3 5 -> 4��
	// rightVec �ε��� 8���� �����Ҷ� -> ������ 5, 3, 2, 1, 4 -> �ִ���� 4 + 1 -> 1 2 3 5 6 -> 5��
	// rightVec �ε��� 9���� �����Ҷ� -> ������ 6, 5, 7, 9, 3, 2, 1, 4 -> �ִ���� 5 + 1 -> 1 2 3 5 6 10 -> 6��
	// rightVec �ε��� 10���� �����Ҷ� -> ������ 6, 5, 7, 3, 2, 1, 4 -> �ִ���� 5 + 1 -> 1 2 3 5 6 8 -> 6��
	length[1] = 1;
	int result = 1;

	// rightVec[�ε���] ������ ���鼭 rightVec[�ε���]���� �������� �� �ִ���̿� + 1 �� ����
	for (int i = 2; i < n + 1; i++)
	{
		// rightVec[�ε���] ������ ���鼭 rightVec[�ε���]���� �������� �� �ִ����
		int maxLength = 0;

		for (int j = i - 1; j > 0; j--)
		{
			if (rightVec[i] > rightVec[j])
			{
				if (maxLength < length[j])
				{
					maxLength = length[j];
				}
			}
		}

		// ���� �ִ���̿� + 1
		length[i] = maxLength + 1;

		// �ִ� �� ���� ����
		if (result < length[i])
		{
			result = length[i];
		}
	}

	cout << result << '\n';

	return 0;
}