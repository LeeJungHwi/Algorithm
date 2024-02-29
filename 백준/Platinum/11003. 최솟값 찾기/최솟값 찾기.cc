#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 숫자 구조체
struct Num
{
	int number; // 숫자
	int limit; // 인덱스 몇까지 유효한지

	// 생성자
	Num() {}
	Num(int num, int lim) : number(num), limit(lim) {}

	// 최소힙
	bool operator<(const Num &num) const
	{
		return number > num.number;
	}
};

// 최솟값 찾기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// n개 수, L
	// D_i = A_i-L+1 ~ A_i 중 최솟값
	// D에 저장된 수 출력하기

	int n, l; // N, L 12, 3
	cin >> n >> l;

	priority_queue<Num> pq;

	int num; // 숫자

	// 1 5 2 3 6 2 3 7 3 5 2 6
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		// 숫자를 우선순위 큐에 limit을 i + l - 1 로 해서 저장
		// 우선순위큐 탑 limit이 i보다 작으면 pop
		// 유효한 숫자 중 최소힙에서 하나 꺼내서 출력

		pq.push(Num(num, i + l - 1)); // 1은 2까지 유효, 5는 3까지 유효, 2는 6까지 유효

		while (pq.top().limit < i)
		{
			pq.pop();
		}

		cout << pq.top().number << ' ';
	}

	return 0;
}