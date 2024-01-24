#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// N!�� 0�� ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	// 12! = 12 11 10 9 8 7 6 5 4 3 2 1
	// 2 * 5�� �ν��̹Ƿ� ���ӵ� 0�� ������ 2��
	// 2�� 5�� ���� �߿��� �������� ���ؾ���
	// 5�� ������ 2�� �������� �׻� �����Ƿ� 5�� ������ ���ؾ���
	// 5�� ����� �ݺ��� ���鼭 5�� ������ �������� ���������� ���� �� ���� Ƚ�� ī����

	int divideCnt = 0;

	for (int i = 5; i < n + 1; i += 5)
	{
		int share = i; // �� �ʱ�ȭ

		while (true)
		{
			if (share % 5 != 0) // 5�� ������ �������� ������ ����
			{
				break;
			}

			share = share / 5; // �� ����
			divideCnt++; // ���� Ƚ�� ī����
		}
	}

	cout << divideCnt << '\n';

	return 0;
}