#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> players(9); // 선수 실력 저장 1 2 3 4 5 6 7 8 9
vector<int> firstTeam, secondTeam, thirdTeam; // 각 팀 뽑은선수 저장
int minGap = 2147000000; // 실력차 최소값

// DFS
void DFS(int L, int firstCnt, int secondCnt, int thirdCnt)
{
	if (L == 9 || (firstCnt == 3 && secondCnt == 3 && thirdCnt == 3)) // 종료 조건 : 선수 수를 넘어갔거나 각 팀을 3명씩 모두 뽑은 경우
	{
		if (L == 9) // 선수 수를 넘어간 경우
		{
			if (!(firstCnt == 3 && secondCnt == 3 && thirdCnt == 3)) // 각 팀을 모두 3명씩 뽑은게 아니면 리턴
			{
				return;
			}
		}

		// 각 팀을 모두 3명씩 뽑았다면 실력차 최소값 갱신

		int firstScore = 0, secondScore = 0, thirdScore = 0; // 각 팀 점수

		for (int i = 0; i < 3; ++i)
		{
			firstScore += players[firstTeam[i]]; // 첫번째 팀 점수
			secondScore += players[secondTeam[i]]; // 두번째 팀 점수
			thirdScore += players[thirdTeam[i]]; // 세번째 팀 점수
		}

		int maxScore = max({ firstScore, secondScore, thirdScore }); // 가장 실력이 높은 팀 점수
		int minScore = min({ firstScore, secondScore, thirdScore }); // 가장 실력이 낮은 팀 점수

		minGap = min(minGap, maxScore - minScore); // 실력차 최소값 갱신
	}
	else
	{
		firstTeam.push_back(L); // 선수 뽑음
		DFS(L + 1, firstCnt += 1, secondCnt, thirdCnt); // 첫번째 팀 뽑은횟수 증가
		firstTeam.pop_back(); // 선수 안 뽑음
		firstCnt -= 1; // 첫번째 팀 뽑은횟수 감소

		secondTeam.push_back(L); // 선수 뽑음
		DFS(L + 1, firstCnt, secondCnt += 1, thirdCnt); // 두번째 팀 뽑은횟수 증가
		secondTeam.pop_back(); // 선수 안 뽑음
		secondCnt -= 1; // 두번째 팀 뽑은횟수 감소

		thirdTeam.push_back(L); // 선수 뽑음
		DFS(L + 1, firstCnt, secondCnt, thirdCnt += 1); // 세번째 팀 뽑은횟수 증가
		thirdTeam.pop_back(); // 선수 안 뽑음
		thirdCnt -= 1; // 세번째 팀 뽑은횟수 감소
	}
}

// 팀 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	for (int i = 0; i < 9; ++i)
	{
		cin >> players[i];
	}

	// DFS
	DFS(0, 0, 0, 0);

	cout << minGap;

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//vector<int> players1(9); // 선수 실력 저장 1 2 3 4 5 6 7 8 9
//vector<int> vis1(9); // 처음 3명 선수 뽑았는지 체크
//vector<int> vis2(9); // 남은 6명 중 3명 선수 뽑았는지 체크
//
//int allTeam; // 모든 팀 점수 합
//int firstTeam, secondTeam, thirdTeam; // 각 팀 점수 합
//int minGap = 2147000000; // 실력차 최소값
//
//// DFS
//void DFS(int L, int cnt, int flag)
//{
//	if (flag == 1) // 처음 3명 뽑기
//	{
//		if (L == 9 || cnt == 3) // 종료 조건 : 선수 수를 넘어가거나 선수 세명을 뽑은경우
//		{
//			if (L == 9) // 선수 수를 넘어간경우
//			{
//				if (cnt != 3) // 세명의 선수를 뽑은게 아니면 리턴
//				{
//					return;
//				}
//			}
//
//			firstTeam = 0;
//
//			// 첫번째 팀 점수 합
//			for (int i = 0; i < 9; i++)
//			{
//				if (vis1[i])
//				{
//					firstTeam += players1[i];
//				}
//			}
//
//			// 남은 6명 중 3명 뽑기
//			DFS(0, 3, 2);
//		}
//		else
//		{
//			vis1[L] = true; // 선수 뽑음
//			DFS(L + 1, cnt += 1, 1);
//			vis1[L] = false; // 선수 안 뽑음
//			DFS(L + 1, cnt -= 1, 1);
//		}
//	}
//	else if (flag == 2) // 남은 6명 중 3명 뽑기
//	{
//		if (L == 9 || cnt == 6) // 종료 조건 : 선수 수를 넘어가거나 선수 세명을 더 뽑은경우
//		{
//			if (L == 9) // 선수 수를 넘어간경우
//			{
//				if (cnt != 6) // 세명의 선수를 더 뽑은게 아니면 리턴
//				{
//					return;
//				}
//			}
//
//			secondTeam = 0;
//
//			// 두번째 팀 점수 합
//			for (int i = 0; i < 9; i++)
//			{
//				if (vis2[i])
//				{
//					secondTeam += players1[i];
//				}
//			}
//
//			thirdTeam = 0;
//
//			// 세번째 팀 점수 합
//			thirdTeam = allTeam - firstTeam - secondTeam;
//
//			// 가장 높은 팀과 가장 낮은 팀의 실력차
//			int maxTeam = max(firstTeam, secondTeam);
//			maxTeam = max(maxTeam, thirdTeam);
//
//			int minTeam = min(firstTeam, secondTeam);
//			minTeam = min(minTeam, thirdTeam);
//
//			int gapTeam = maxTeam - minTeam;
//
//			// 실력차 최소값 갱신
//			if (minGap > gapTeam)
//			{
//				minGap = gapTeam;
//			}
//		}
//		else
//		{
//			if (!vis1[L]) // 이미 뽑은 3명은 제외
//			{
//				vis2[L] = true; // 선수 뽑음
//				DFS(L + 1, cnt += 1, 2);
//				vis2[L] = false; // 선수 안 뽑음
//				DFS(L + 1, cnt -= 1, 2);
//			}
//		}
//	}
//}
//
//// 팀 만들기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> players1[i];
//
//		allTeam += players1[i];
//	}
//
//	// DFS
//	DFS(0, 0, 1);
//
//	cout << minGap;
//
//	return 0;
//}