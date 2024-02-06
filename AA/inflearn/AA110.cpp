#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 일정 구조체
struct Schedule
{
	int start;
	int end;
	int efficient;

	Schedule() : start(0), end(0), efficient(0) {}; // 생성자

	Schedule(int st, int et, int ef) // 생성자
	{
		start = st;
		end = et;
		efficient = ef;
	}

	bool operator<(const Schedule &schedule)const // 시작시간 오름차순
	{
		return start < schedule.start;
	}
};

// 효율적인 공부
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, r; // N, M, R 13, 5, 2
	cin >> n >> m >> r;

	vector<Schedule> schedules(m); // 일정 구조체 저장
	vector<int> maxEfficients(m + 1); //  몇번째 일정을 마지막에 수행했는지에 따라 최대효율성 갱신

	//	3 5 20
	//	4 7 16
	//	1 2 5
	//	11 13 7
	//	9 10 6
	int st, et, ef; // 시작시간 끝나는시간 효율성

	for (int i = 0; i < m; i++)
	{
		cin >> st >> et >> ef;

		schedules[i] = Schedule(st, et + r, ef); // et는 휴식시간까지 더해서 초기화
	}

	sort(schedules.begin(), schedules.end()); // (1 4 5) (3 7 20) (4 9 16) (9 12 6) (11 15 7)

	int result = 0; // 최대효율성

	for (int i = 0; i < m; i++) // i번째 일정을 마지막으로 수행함
	{
		maxEfficients[i] = schedules[i].efficient;

		for (int j = i - 1; j > -1; j--)  // i번째 일정의 이전 작업을 보면서
		{
			// 이전 작업의 끝나는 시간보다 i번째 일정의 시작시간이 크거나 같아야 수행할수있음
			// 이전 작업의 최대효율성과 i번째 일정의 효율성을 더한것이 기존 i번째 일정의 최대효율성보다 커야 갱신할수있음
			if (schedules[j].end <= schedules[i].start && maxEfficients[j] + schedules[i].efficient > maxEfficients[i])
			{
				maxEfficients[i] = maxEfficients[j] + schedules[i].efficient; // i번째 일정을 마지막으로 수행했을때 최대효율성 갱신
			}
		}

		// 최대효율성 갱신
		if (result < maxEfficients[i])
		{
			result = maxEfficients[i];
		}
	}

	cout << result << '\n';

	return 0;
}
// 핵심
// DFS -> 시간초과 -> DP로 해결

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//int n, m, r; // N, M, R 13, 5, 2
//vector<bool> vis(1001); // 방문체크
//int maxEfficient; // 최대 효율성
//
//// 일정 구조체
//struct Schedule
//{
//	int start;
//	int end;
//	int efficient;
//
//	Schedule() : start(0), end(0), efficient(0) {}; // 생성자
//
//	Schedule(int st, int et, int ef) // 생성자
//	{
//		start = st;
//		end = et;
//		efficient = ef;
//	}
//
//	bool operator<(const Schedule &schedule)const // 시작시간 오름차순
//	{
//		return start < schedule.start;
//	}
//};
//
//// DFS
//void DFS(int L, int et, vector<Schedule> &schedules)
//{
//	if (L == m) // 종료조건 : 일정의 개수가 되면 종료
//	{
//		int ef = 0; // 효율성
//
//		for (int i = 0; i < m; i++) // 효율성 누적
//		{
//			if (vis[i])
//			{
//				ef += schedules[i].efficient;
//			}
//		}
//
//		if (maxEfficient < ef) // 최대효율성 갱신
//		{
//			maxEfficient = ef;
//		}
//	}
//	else
//	{
//		int st = schedules[L].start; // 일정 시작시간
//
//		if (st >= et) // 할수있는 일정이면
//		{
//			vis[L] = true; // 할거
//			DFS(L + 1, schedules[L].end, schedules); // 했으면 일정의 끝나는시간
//			vis[L] = false; // 안 할거
//			DFS(L + 1, et, schedules); // 안 했으면 넘어온 끝나는시간
//		}
//		else // 할수없는 일정이면
//		{
//			DFS(L + 1, et, schedules); // 못하므로 넘어온 끝나는시간
//		}
//	}
//}
//
//// 효율적인 공부
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	cin >> n >> m >> r;
//
//	vector<Schedule> schedules(m); // 일정 구조체 저장
//
//	//	3 5 20
//	//	4 7 16
//	//	1 2 5
//	//	11 13 7
//	//	9 10 6
//	int st, et, ef; // 시작시간 끝나는시간 효율성
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> st >> et >> ef;
//
//		schedules[i] = Schedule(st, et + r, ef); // et는 휴식시간까지 더해서 초기화
//	}
//
//	sort(schedules.begin(), schedules.end()); // (1 4 5) (3 7 20) (4 9 16) (9 12 6) (11 15 7)
//
//	// DFS
//	DFS(0, 0, schedules);
//
//	cout << maxEfficient << '\n';
//
//	return 0;
//}