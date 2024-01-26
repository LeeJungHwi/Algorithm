#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 영지 선택(large)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int groundH, groundW; // 전체땅 세로 가로 6 7

	cin >> groundH >> groundW;

	vector<vector<int> > ground(groundH, vector<int>(groundW)); // 전체 땅

	for (int i = 0; i < groundH; i++)
	{
		for (int j = 0; j < groundW; j++)
		{
			cin >> ground[i][j];
		}
	}

	int territoryH, territoryW; // 현수가 하사받을 땅 세로 가로 2 3
	cin >> territoryH >> territoryW;

	// 영지 선택하기
	// 3 5 1 3 1 3 2
	// 1 2 1 3 1 1 2
	// 1 3 1 5 1 3 4
	// 5 1 1 3 1 3 2
	// 3 1 1 3 1 1 2
	// 1 3 1 3 1 2 2

	// 처음 영지의 오렌지 나무 개수 값 구하기
	// 다음영지부터 : 이전 영지의 오렌지 나무 개수 값 - 첫줄 오렌지 나무 개수 합 + 현재 영지의 마지막줄 오렌지 나무 개수 합

	// 이전 - (0,0) (1,0) + (0,3) (1,3)
	// 이전 - (0,1) (1,1) + (0,4) (1,4)
	// 이전 - .... + ....
	// 이전 - (0,3) (1,3) + (0,6) (1,6)
	// 이전 - (1,0) (2,0) + (1,3) (2,3)
	// 이전 - (1,1) (2,1) + (1,4) (2,4)
	// 이전 - .... + ....
	// 이전 - (1,3) (2,3) + (1,6) (2,6)

	int maxOrangeTreeCnt = 0; // 오렌지 나무 최대 개수

	for (int i = 0; i < groundH - territoryH + 1; i++) // 다음영지부터 : 이전 영지의 오렌지 나무 개수 값 - 첫줄 오렌지 나무 개수 합 + 현재 영지의 마지막줄 오렌지 나무 개수 합
	{
		int orangeTreeCnt = 0;
		int standardOrangeTreeCnt = 0;

		for (int j = 0; j < groundW - territoryW + 1; j++)
		{
			// 이전 값이 없으면 합 구하기
			if (orangeTreeCnt == 0)
			{
				// 이전 기준값이 없으면 전체 합 구하기
				if (standardOrangeTreeCnt == 0)
				{
					for (int k = i; k < territoryH + i; k++) // 영지 별 오렌지 나무 개수 합
					{
						for (int l = j; l < territoryW + j; l++)
						{
							orangeTreeCnt += ground[k][l];
						}
					}

					standardOrangeTreeCnt = orangeTreeCnt;
				}
				else // 이전 기준값이 있으면 재사용해서 구하기
				{
					for (int k = j; k < territoryW + j; k++) // 영지 별 오렌지 나무 개수 합
					{
						orangeTreeCnt = orangeTreeCnt - ground[k - 1][j] + ground[k + territoryH - 1][j];
					}
				}
			}
			else // 이전 값이 있으면 재사용해서 구하기
			{
				for (int k = i; k < territoryH + i; k++) // 영지 별 오렌지 나무 개수 합
				{
					orangeTreeCnt = orangeTreeCnt - ground[k][j - 1] + ground[k][j + territoryW - 1];
				}
			}

			if (maxOrangeTreeCnt < orangeTreeCnt) // 오렌지 나무가 최대인 영지 갱신
			{
				maxOrangeTreeCnt = orangeTreeCnt;
			}
		}
	}

	cout << maxOrangeTreeCnt << '\n';

	return 0;
}
// 핵심
// 이전 값 재사용