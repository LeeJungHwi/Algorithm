#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
using namespace std;

// ���� �κ� ��������
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");
	//freopen("input.txt", "rt", stdin);

	int n; // N
	scanf_s("%d", &n);

	int num; // ����

	int preNum = 0; // ���� ����
	int length = 0; // �������� ����
	int maxLength = 0; // �������� �ִ����

	// �������� �ִ���� ���ϱ�
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num);

		if (preNum <= num) // ��������
		{
			length++;

			if (maxLength < length)
			{
				maxLength = length;
			}
		}
		else
		{
			length = 1; // �������� �۾� �ʱ�ȭ �Ǿ����� ���Ӱ� �����ϹǷ� ù ���� �κ�
		}

		preNum = num;
	}

	printf("%d\n", maxLength);

	return 0;
}

// �ٽ�
// �ð��ʰ� -> printf scanf�� cout cin���� ����