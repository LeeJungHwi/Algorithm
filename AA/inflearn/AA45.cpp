#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// ���ֱ��ϱ�(�����۽�)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	vector<int> princes(n); // ���̼����� n���� ����
	vector<bool> cantGo(n); // �������� ���� üũ

	for (int i = 0; i < n; i++)
	{
		princes[i] = i; // 0 1 2 3 4 5 6 7
	}

	// ���ָ� ���Ϸ� �� ���� ���ϱ�
	// 1 2 3 -> 3 ����
	// 4 5 6 -> 6 ����
	// 7 8 1 -> 1 ����
	// 2 4 5 -> 5 ����
	// 7 8 2 -> 2 ����
	// 4 7 8 -> 8 ����
	// 4 7 4 -> 4 ����
	// 7�� ���ڰ� ���� ���ϱ�

	int shoutNum = 0; // ��ġ�� ����
	int canGoCnt = n; // ���Ϸ� �����ִ� ���� ��
	int preShout = 0; // ������ ��ȣ�� ��ģ ����

	for (int i = 0; i < n; i++)
	{
		if (!cantGo[i]) // ���ܵ� ���ڰ� �ƴҶ���
		{
			shoutNum++; // ��ȣ ��ġ��

			if (shoutNum == k) // ��ģ ��ȣ�� k�� ����
			{
				cantGo[i] = true;
				canGoCnt--;
				shoutNum = 0;

				if (canGoCnt == 1) // �� �� �ִ� ���ڰ� �Ѹ��̸� ����
				{
					break;
				}
			}

			preShout = princes[i]; // ������ ��ȣ�� ��ģ ����
		}

		if (i == n - 1) // ������ ���ڱ��� ���� ó�� ���ڷ� �ݺ�
		{
			i = -1;
		}
	}

	cout << preShout + 1 << '\n';

	return 0;
}
// �ٽ�
// ������ ��ȣ�� ��ģ ���� ���� Ÿ�̹�