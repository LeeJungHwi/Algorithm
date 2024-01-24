#include <iostream>
#include <fstream>
using namespace std;

// ��������
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N�� M��
	cin >> n >> m;

	int noise; // ����ġ
	int time = 0; // �溸�� �ð�
	int maxTime = 0; // �ִ� �溸�� �ð�

	// �ִ� ���� �溸�� ���ϱ�
	for (int i = 0; i < n; i++)
	{
		cin >> noise;

		if (noise > m) // M���� ������ �溸�� �ð� ����
		{
			time++;

			if (time > maxTime) // �ִ� �溸�� �ð� ����
			{
				maxTime = time;
			}
		}
		else // �ƴϸ� �ð� �ʱ�ȭ
		{
			time = 0;
		}
	}

	cout << maxTime << '\n';

	return 0;
}