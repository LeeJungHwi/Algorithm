#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 문제 구조체
struct Problem
{
	int deadLine; // 데드라인
	long long cupRamyeonCnt; // 컵라면 수

	// 생성자
	Problem() {}
	Problem(int d, long long c) : deadLine(d), cupRamyeonCnt(c) {}

	// 정렬기준 : 데드라인이 다르면 데드라인 오름차순, 데드라인이 같으면 컵라면 수 내림차순
	bool operator<(const Problem &problem)const
	{
		if (deadLine != problem.deadLine)
		{
			return deadLine < problem.deadLine;
		}

		return cupRamyeonCnt > problem.cupRamyeonCnt;
	}
};

// 최소힙
struct Num
{
	long long number; // 숫자

	// 생성자 
	Num() {}
	Num(long long n) : number(n) {}

	// 최소힙
	bool operator<(const Num &num)const
	{
		return number > num.number;
	}
};

// 컵라면 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<Problem> schedules(n); // 각 문제 저장

	int deadL; // 각 문제 데드라인
	long long cupR; // 각 문제 컵라면 수

	//	1 6
	//	1 7
	//	3 2
	//	3 1
	//	2 4
	//	2 5
	//	6 1
	for (int i = 0; i < n; i++)
	{
		cin >> deadL >> cupR;

		schedules[i] = Problem(deadL, cupR);
	}

	// 문제 정렬, 데드라인 오름차순, 컵라면 수 내림차순
	sort(schedules.begin(), schedules.end());

	priority_queue<Num> minHeap; // 작은 값부터 pop하기 위해 최소 힙 사용
	long long maxCnt = 0; // 최대 컵라면 수

	for (int i = 0; i < n; i++)
	{
		minHeap.push(Num(schedules[i].cupRamyeonCnt)); // 현재 문제의 컵라면 수를 우선순위큐에 저장
		maxCnt += schedules[i].cupRamyeonCnt; // 현재까지의 최대 컵라면 수에 현재 문제의 컵라면 수를 더함

		// 데드라인을 초과하는 경우
		// 데드라인을 초과하는 문제 중 가장 작은 컵라면 수를 가진 문제를 제거
		if (minHeap.size() > schedules[i].deadLine)
		{
			maxCnt -= minHeap.top().number;
			minHeap.pop();
		}
	}

	cout << maxCnt << '\n';

	return 0;
}
