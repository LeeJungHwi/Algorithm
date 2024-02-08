#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// ���� ã��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // ö���� �� ���ڿ� �� �Ϻκ� 3210232102321023
	cin >> inputString;

	string pattern = ""; // ���� ���ڿ� 32102

	int n; // N 52
	cin >> n;

	// ���� ã��
	// ������ �Է¹��ڿ�ũ�� / 2���� ��� üũ
	// ....
	// ������ 2���� ��� üũ
	// ������ 1���� ��� üũ
	for (int i = inputString.size() / 2; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (inputString[j] == inputString[j + i]) // ������ ������ �ϳ��� �߰�
			{
				pattern += inputString[j];
				continue;
			}

			// ������ �ٸ��� ���� �ʱ�ȭ �� ����
			pattern.clear();
			break;
		}

		// ������ ������� ������ ������ ã�����̹Ƿ� ����
		if (!pattern.empty())
		{
			break;
		}
	}

	// �� ������ ���� �� * (n / ���ϱ���) + 0����(n % ���ϱ���)���� ���ϼ���

	int onePatternSum = 0; // �� ������ ���� �� 8

	for (int i = 0; i < pattern.size(); i++)
	{
		onePatternSum += pattern[i] - '0';
	}

	int result = onePatternSum * (n / pattern.size()); // ������ ���� n��ŭ ������ ���� ���� 85

	for (int i = 0; i < n % pattern.size(); i++)
	{
		result += pattern[i] - '0';
	}

	cout << result << '\n';

	return 0;
}