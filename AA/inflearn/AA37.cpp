#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// LRU
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int s, n; // S, N
	cin >> s >> n;

	int taskNum; // �۾���ȣ

	vector<int> casheMem(s, 0); // ĳ�ø޸� 0 0 0 0 0

	// ���� �ֱ� �۾��� ĳ���� �Ǿ� -> ť�� �����Ϸ� ������ -> ��� ������ ������ -> ���ͷ� ����
	// ĳ�ù̽� -> �Է����� ���� �۾��� ĳ�ø޸𸮿� ������ ĳ���� �Ǿ� -> ĳ�ø޸𸮰� ����á���� ���� ������ �۾� ����
	// ĳ����Ʈ -> �Է����� ���� �۾��� ĳ�ø޸𸮿� ������ ĳ�ÿ� ���� ���� ��Ҹ� �������ķ� ĳ�ø޸� �Ǿտ� ����

	for (int i = 0; i < n; i++)
	{
		cin >> taskNum;

		bool isHit = false;

		for (int j = 0; j < s; j++)
		{
			if (casheMem[j] == taskNum) // ĳ�ø޸𸮿� ���� �۾��� �ִ°�� -> ĳ����Ʈ
			{
				for (int k = j - 1; k > -1; k--) // ��� �� ���� 0�� ���� ������ ����Ʈ
				{
					casheMem[k + 1] = casheMem[k];
				}

				casheMem[0] = taskNum;
				isHit = true;
				break;
			}
		}

		// ĳ�ø޸𸮿� ���� �۾��� ���°�� -> ĳ�ù̽�
		if (!isHit)
		{
			for (int j = s - 2; j > -1; j--) // 0~������ �� ��Ҹ� ������ ����Ʈ �� task ����
			{
				casheMem[j + 1] = casheMem[j];
			}

			casheMem[0] = taskNum;
		}
	}

	for (int i = 0; i < s; i++)
	{
		cout << casheMem[i] << ' ';
	}

	return 0;
}

// �ٽ�
// ť�� �ε����� ���� �Ұ�