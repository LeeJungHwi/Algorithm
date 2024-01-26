#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 영지 선택(small)
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

	int maxOrangeTreeCnt = 0; // 오렌지 나무 최대 개수

	for (int i = 0; i < groundH - territoryH + 1; i++)
	{
		for (int j = 0; j < groundW - territoryW + 1; j++)
		{
			int orangeTreeCnt = 0; // 오렌지 나무 개수

			for (int k = i; k < territoryH + i; k++) // 영지 별 오렌지 나무 개수 합
			{
				for (int l = j; l < territoryW + j; l++)
				{
					orangeTreeCnt += ground[k][l];
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