#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;

// ������
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n; // N
	scanf_s("%d", &n);

	vector<int> playerAbility(n); // ���� �Ƿ� ����

	int ability; // ���� �Ƿ�

	// ó�� ������ 1��
	scanf_s("%d", &ability);
	playerAbility[0] = ability;
	printf("1 ");

	int highAbilityPlayer = 0; // �Ƿ��� ���� ����
	int maxAbility = playerAbility[0]; // �Ƿ� �ִ�
	int minAbility = playerAbility[0]; // �Ƿ� �ּ�

	for (int i = 1; i < n; i++) // 2. �ι�° �������ʹ� ���� �տ� �Ƿ��� ������ ������ ������� üũ
	{
		scanf_s("%d", &ability);
		playerAbility[i] = ability;

		// max �� min ���ŵǴ� ��� ó��
		if (maxAbility < playerAbility[i]) // max�� ���ŵǸ� 1�� ó�� �� continue
		{
			maxAbility = playerAbility[i];
			printf("1 ");
			continue;
		}
		else if (minAbility > playerAbility[i]) // min�� ���ŵǸ� ���� ��� �״�� �� continue
		{
			minAbility = playerAbility[i];
			printf("%d ", i + 1);
			continue;
		}

		for (int j = 0; j < i; j++)
		{
			if (playerAbility[i] <= playerAbility[j])
			{
				highAbilityPlayer++;
			}
		}

		// ���� ������ ������� üũ�� ����
		printf("%d ", ++highAbilityPlayer);

		// �ʱ�ȭ
		highAbilityPlayer = 0;
	}

	return 0;
}

// �ٽ�
// Ÿ�Ӹ��� -> ��ǻ�ͼ����� �� ���Ƽ�
// �˰��� ��ü�� ������