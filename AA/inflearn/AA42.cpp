#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// �̺а˻�
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M
	cin >> n >> m;

	int num; // ����
	vector<int> nums(n); // ���� ����

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		nums[i] = num; // 23 87 65 12 57 32 99 81
	}

	sort(nums.begin(), nums.end()); // 12 23 32 57 65 81 87 99

	// �̺а˻�
	// ���ذ� : (ó���ε��� + �������ε���) / 2�� ���� ��
	// ���ذ��� ã�����ϴ°� ��
	// ������� : ���ذ� �ε����� ��ġ
	// ū��� : ó���ε����� ���ذ��ε��� + 1���ϰ� �̺а˻�
	// ������� : �������ε����� ���ذ��ε��� - 1���ϰ� �̺а˻�
	// �˻��� �����ϴ°�� : ó���ε��� > �������ε���

	int firstIndex = 0; // ó���ε���
	int lastIndex = n - 1; // �������ε���
	int keyIndex = 0; // ã���� �ϴ� ���� ��ġ

	while (firstIndex <= lastIndex) // �������� �ʾ������� �ݺ�
	{
		int standardIndex = (firstIndex + lastIndex) / 2; // ���ذ� �ʱ�ȭ

		if (nums[standardIndex] == m) // �������
		{
			keyIndex = standardIndex;
			break;
		}
		else if (nums[standardIndex] < m) // ū���
		{
			firstIndex = standardIndex + 1; // ó���ε��� ����
		}
		else if (nums[standardIndex > m]) // �������
		{
			lastIndex = standardIndex - 1; // �������ε��� ����
		}
	}

	cout << keyIndex + 1 << '\n';

	return 0;
}