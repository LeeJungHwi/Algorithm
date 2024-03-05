#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 절댓값 기준 구조체
struct Num
{
	int number; // 숫자

	// 생성자
	Num() {}
	Num(int n) : number(n) {}

	// 절댓값 기준 오름차순
	bool operator<(const Num &num)const
	{
		if (abs(number) != abs(num.number))
		{
			return abs(number) < abs(num.number);
		}

		return number < num.number;
	}
};

// 최대힙
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 두가지연산
	// 1. 0이아닌 x를 넣는다
	// 2. 절댓값이 가장큰값을 출력하고 제거
	// 절댓값이 큰값이 여러개면 그 중 큰수 출력하고 제거
	// 빈배열일경우 0 출력

	int n; // N 13
	cin >> n;

	priority_queue<Num> absMaxHeap;

	int op; // 연산

	//	0
	//	1
	//	2
	//	0
	//	0
	//	3
	//	2
	//	1
	//	0
	//	0
	//	0
	//	0
	//	0
	while (n--)
	{
		cin >> op;

		// 0이 아니면 우선순위큐에 저장
		if (op != 0)
		{
			absMaxHeap.push(Num(op));

			continue;
		}

		// 0이면 출력하고 pop
		// 큐가 비었으면 0 출력
		if (absMaxHeap.empty())
		{
			cout << 0 << '\n';

			continue;
		}

		cout << absMaxHeap.top().number << '\n';
		absMaxHeap.pop();
	}

	return 0;
}