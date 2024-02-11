#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n, m; // N, M 7, 3
vector<int> clubScores(300); // 동아리 회원의 수학점수 저장 50 20 30 70 20 60 30

// 만들어지는 팀의 수를 리턴하는 함수
int GetTeamCnt(int teamMaxSum)
{
	int teamScores = 0; // 각 팀의 합
	int teamCnt = 1; // 만들어진 팀의 수

	for (int i = 0; i < n; i++)
	{
		if (teamScores + clubScores[i] > teamMaxSum) // 각 팀의 합의 최대값을 넘어간경우
		{
			teamCnt++; // 팀이 하나 만들어짐
			teamScores = clubScores[i]; // i번째 수학점수를 넣으면 초과하므로 i번째부터 새로운 팀으로
		}
		else
		{
			teamScores += clubScores[i]; // 아직 최대값을 넘기지 않았으면 수학점수 누적
		}
	}

	return teamCnt; // 만들어진 팀의 수 리턴
}

// 조 나누기
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int first = 0; // 처음
	int last = 0; // 마지막

	// 50 20 30 70 20 60 30
	for (int i = 0; i < n; i++)
	{
		cin >> clubScores[i];

		first = max(first, clubScores[i]); // 70 : 각 조의 합 중 최대값은 개인회원 점수 중 최대값보단 큼
		last += clubScores[i]; // 280 : 각 조의 합 중 최대값은 모든회원 점수의 합보단 작음
	}

	int result; // 조의 합의 최대값들 중 최소값

	// 조의 합의 최대값들 중 최소값 찾아서 출력
	while (first <= last) // first와 last가 역전되면 종료
	{
		int avg = (first + last) / 2; // 조의 합의 최대값

		if (GetTeamCnt(avg) <= m) // avg로 m개의 팀을 만들 수 있다면
		{
			result = avg; // 조의 합의 최대값들 중 최소값 갱신
			last = avg - 1; // 마지막 갱신 
		}
		else // 불가능한 조의 합의 최대값
		{
			first = avg + 1; // 처음 갱신
		}
	}

	cout << result;

	return 0;
}
// DFS -> 시간초과 -> 이진탐색으로 해결

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//int n, m; // N, M 7, 3
//vector<int> clubScores(300); // 동아리 회원의 수학점수 저장
//vector<vector<int> > teamScores(300); // 각 조 수학점수 저장
//int result = 2147000000; // 각 조의 합의 최대값들 중 최소값
//
//// DFS
//void DFS(int L, int cnt)
//{
//	if (L == n || cnt == n) // 종료조건 : 동아리 회원 수를 넘어가거나 동아리 회원 수를 선택한경우
//	{
//		if (L == n) // 동아리 회원 수를 넘긴경우
//		{
//			if (cnt != n) // 동아리 회원 수를 선택하지 않았으면 리턴
//			{
//				return;
//			}
//		}
//
//		for (int i = 0; i < m; i++) // 어느 하나의 조라도 조원이 없으면 리턴
//		{
//			if (teamScores[i].empty())
//			{
//				return;
//			}
//		}
//
//		// 각 조의 합의 최대값 구하기
//
//		int maxSum = 0; // 조의 합의 최대값
//
//		for (int i = 0; i < m; i++) // 조의 개수만큼 돌면서 조의 합 구하기
//		{
//			int sum = 0; // 조의 합
//
//			for (int j = 0; j < teamScores[i].size(); j++)
//			{
//				sum += clubScores[teamScores[i][j]]; // 조원의 점수 합 누적
//			}
//
//			// 조의 합의 최대값 갱신
//			maxSum = max(maxSum, sum);
//		}
//
//		// 각 조의 합의 최대값들 중 최소값 갱신
//		result = min(result, maxSum);
//	}
//	else
//	{
//		// 조원 뽑기
//		for (int i = 0; i < m; i++)
//		{
//			teamScores[i].push_back(L); // 회원 뽑음
//			DFS(L + 1, cnt += 1); // 뽑은횟수 증가
//			teamScores[i].pop_back(); // 회원 안 뽑음
//			cnt -= 1; // 뽑은횟수 감소
//		}
//	}
//}
//
//// 조 나누기
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	cin >> n >> m;
//
//	// 50 20 30 70 20 60 30
//	for (int i = 0; i < n; i++)
//	{
//		cin >> clubScores[i];
//	}
//
//	// DFS
//	DFS(0, 0);
//
//	cout << result << '\n';
//
//	return 0;
//}