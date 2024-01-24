#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;

// 마라톤
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n; // N
	scanf_s("%d", &n);

	vector<int> playerAbility(n); // 선수 실력 저장

	int ability; // 선수 실력

	// 처음 선수는 1등
	scanf_s("%d", &ability);
	playerAbility[0] = ability;
	printf("1 ");

	int highAbilityPlayer = 0; // 실력이 높은 선수
	int maxAbility = playerAbility[0]; // 실력 최대
	int minAbility = playerAbility[0]; // 실력 최소

	for (int i = 1; i < n; i++) // 2. 두번째 선수부터는 본인 앞에 실력이 부족한 선수가 몇명인지 체크
	{
		scanf_s("%d", &ability);
		playerAbility[i] = ability;

		// max 및 min 갱신되는 경우 처리
		if (maxAbility < playerAbility[i]) // max가 갱신되면 1등 처리 후 continue
		{
			maxAbility = playerAbility[i];
			printf("1 ");
			continue;
		}
		else if (minAbility > playerAbility[i]) // min이 갱신되면 본인 등수 그대로 후 continue
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

		// 높은 선수가 몇명인지 체크된 상태
		printf("%d ", ++highAbilityPlayer);

		// 초기화
		highAbilityPlayer = 0;
	}

	return 0;
}

// 핵심
// 타임리밋 -> 컴퓨터성능이 안 좋아서
// 알고리즘 자체는 쉬웠음