#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n; // N 3
vector<pair<int, int> > eggs(8); // 계란(내구도, 무게) (8, 5) (1, 100) (3, 5)
int maxBreakCnt; // 계란을 깨는 최대 개수

// DFS
void DFS(int L, int breakCnt)
{
	if (L == n) // 종료조건 : 가장 오른쪽 계란인경우
	{
		// 계란을 깨는 최대 개수 갱신
		maxBreakCnt = max(maxBreakCnt, breakCnt);

		return;
	}
	else
	{
		// 계란을 깨는 최대 개수 갱신
		maxBreakCnt = max(maxBreakCnt, breakCnt);

		// 들고있는 계란이 아직 깨지지 않았으면
		if (eggs[L].first > 0)
		{
			// 계란 돌면서
			for (int i = 0; i < n; i++)
			{
				// 자신을 제외한 나머지 계란중 깨지지않은 계란이면
				if (eggs[i].first > 0 && i != L)
				{
					// 계란 쳤음
					eggs[i].first -= eggs[L].second;
					eggs[L].first -= eggs[i].second;

					if (eggs[i].first <= 0) // 들고있는 계란에 의해 부딪힌 계란 처리
					{
						breakCnt++;
					}

					if (eggs[L].first <= 0) // 들고있는 계란 처리
					{
						breakCnt++;
					}

					DFS(L + 1, breakCnt); // 다음 계란 처리

					// 계란 안 쳤음
					if (eggs[i].first <= 0) // 들고있는 계란에 의해 부딪힌 계란 처리
					{
						breakCnt--;
					}

					if (eggs[L].first <= 0) // 들고있는 계란 처리
					{
						breakCnt--;
					}

					eggs[i].first += eggs[L].second;
					eggs[L].first += eggs[i].second;
				}
			}
		}
		else // 들고있는 계란이 깨진계란이면 다음계란
		{
			DFS(L + 1, breakCnt); // 다음 계란 처리
		}
	}
}

// 계란으로 계란치기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 계란으로 계란을 치면 각 계란의 내구도는 상대 계란의 무게만큼 깎임
	// 내구도가 0 이하가 되면 계란이 깨짐
	// 일렬로 놓여있는 계단에대해 왼쪽부터 차례로 한번씩만 다른계란을 쳐 최대한 많은 계란을 깨야함
	// 1. 가장 왼쪽 계란부터 들어서 아직 깨지지않은 다른계란 하나를 친다
	// 2. 가장 오른쪽 계란까지 계란을 치면 종료한다

	cin >> n;

	//	8 5
	//	1 100
	//	3 5
	int durability; // 내구도
	int weight; // 무게

	for (int i = 0; i < n; i++)
	{
		cin >> durability >> weight;

		eggs[i] = { durability, weight };
	}

	// DFS
	DFS(0, 0);

	cout << maxBreakCnt << '\n';

	return 0;
}