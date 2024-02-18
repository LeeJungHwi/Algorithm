#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 구조체
struct Num
{
	int number; // 숫자
	int count; // 횟수

	// 생성자
	Num() {}
	Num(int num, int cnt) : number(num), count(cnt) {}

	// 횟수가 다르면 횟수로 오름차순
	// 횟수가 같으면 숫자로 오름차순
	bool operator<(const Num &num)const
	{
		if (count != num.count)
		{
			return count > num.count;
		}

		return number > num.number;
	}
};

// 이차원 배열과 연산
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1. A : 3 by 3, 1-based지만 0-based로 하고 r과 c를 1씩 빼줌
	// 2. 1 초마다 정렬
	// 2-1. 행 수 >= 열 수 : 모든 행 정렬
	// 2-2. 행 수 < 열 수 : 모든 열 정렬
	// 정렬 방법
	/*
	등장횟수 카운팅 후 등장횟수가 작은 순서대로 오름차순으로 정렬하되 등장횟수가 같으면 숫자가 작은 순서가 먼저나옴
	3 1 1 은 3이 1번 1이 2번 이므로 3 1 1 2
	3 1 1 2 는 3이 1번 1이 2번 2가 1번 이므로 2,3의 등장횟수가 같으므로 작은 수인 2가 1번 3이 1번 1이 2번 이므로 2 1 3 1 1 2
	2 1 3 1 1 2 는 2가 2번 1이 3번 3이 1번 이므로 3이 1번 2가 2번 1이 3번 이므로 3 1 2 2 1 3
	3 1 2 2 1 3 은 3이 2번 1이 2번 2가 2번 이므로 1,2,3의 등장횟수가 같으므로 작은 순서대로 1이 2번 2가 2번 3이 2번 이므로 1 2 2 2 3 2
	....
	*/
	// 정렬된 결과는 다시 행 또는 열에 넣기때문에 행과 열의 크기가 달라질수있음
	// 각 행과 열은 연산 이후에 가장 큰 크기로 변하며 커진곳은 0이 채워짐
	// 수를 정렬할때는 0은 무시해야함
	// 3 2 0 0을 정렬한다면 0을 무시하므로 3이 1번 2가 1번이고 2,3의 등장횟수가 같으므로 작은순서대로 2 1 3 1이된다
	// 행 또는 열의 크기가 100을 넘어가는 경우 처음 100개를 제외한 나머지는 버림
	// A[r][c]의 값이 k가 되기위한 최소시간 구하기

	int r, c, k; // R, C, K 1, 2, 2
	cin >> r >> c >> k;

	// 1-based지만 0-based로 하고 r과 c를 1씩 빼줌
	r -= 1;
	c -= 1;

	vector<vector<int> > A(3, vector<int>(3)); // 그래프
	vector<int> cnt(101); // 카운팅
	priority_queue<Num> num; // 우선순위 큐

	// 초기 행렬값
	//	1 2 1
	//	2 1 3
	//	3 3 3
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> A[i][j];
		}
	}

	int time = 0; // 연산의 최소시간
	int colSize = 3; // 현재 열 최대크기
	int rowSize = 3; // 현재 행 최대크기

	// 100초가 지나도 A[r][c] == k가 되지 않으면 못함
	while (time != 101)
	{
		// A[r][c] == k면 시간 출력 후 종료
		if (rowSize > c && colSize > r)
		{
			if (A[r][c] == k)
			{
				cout << time << '\n';

				return 0;
			}
		}

		// 2. 1 초마다 정렬
		time++;

		// 2-1. 행 수(열 크기) >= 열 수(행 크기) : 모든 행 정렬
		if (colSize >= rowSize)
		{
			for (int i = 0; i < colSize; i++)
			{
				// 각 행의 숫자 등장횟수 카운팅
				for (int j = 0; j < rowSize; j++)
				{
					cnt[A[i][j]]++;
				}

				// 등장횟수 카운팅이 된 숫자만 우선순위 큐에 저장
				for (int j = 1; j < cnt.size(); j++)
				{
					if (cnt[j] > 0)
					{
						num.push(Num(j, cnt[j]));
					}
				}

				// 큐 크기 * 2가 현재 행 최대크기보다 클때 전체 행 리사이징
				if (num.size() * 2 > rowSize)
				{
					rowSize = num.size() * 2;

					for (int j = 0; j < colSize; j++)
					{
						A[j].resize(rowSize);
					}
				}

				// 큐 크기 * 2가 현재 행 최대크기보다 작을때
				// 큐 크기 * 2부터 현재 행 최대크기까지 0으로 초기화
				if (num.size() * 2 < rowSize)
				{
					for (int j = num.size() * 2; j < rowSize; j++)
					{
						A[i][j] = 0;
					}
				}

				// 행 크기가 100을 넘어가는 경우 처음 100개를 제외한 나머지는 버림
				if (rowSize > 100)
				{
					// 우선순위 큐에서 하나씩 꺼내서 저장 : 100개 까지만
					for (int j = 0; j < 100; j += 2)
					{
						if (!num.empty())
						{
							A[i][j] = num.top().number;
							A[i][j + 1] = num.top().count;
							num.pop();
						}
					}
				}
				else
				{
					// 우선순위 큐에서 하나씩 꺼내서 저장 : 행 크기만큼
					for (int j = 0; j < rowSize; j += 2)
					{
						if (!num.empty())
						{
							A[i][j] = num.top().number;
							A[i][j + 1] = num.top().count;
							num.pop();
						}
					}
				}

				// 큐 초기화
				while (!num.empty())
				{
					num.pop();
				}

				// 카운트 배열 초기화
				for (int j = 1; j < cnt.size(); j++)
				{
					cnt[j] = 0;
				}
			}
		}
		else // 2-2. 행 수(열 크기) < 열 수(행 크기) : 모든 열 정렬
		{
			for (int i = 0; i < rowSize; i++)
			{
				// 각 열의 숫자 등장횟수 카운팅
				for (int j = 0; j < colSize; j++)
				{
					cnt[A[j][i]]++;
				}

				// 등장횟수 카운팅이 된 숫자만 우선순위 큐에 저장
				for (int j = 1; j < cnt.size(); j++)
				{
					if (cnt[j] > 0)
					{
						num.push(Num(j, cnt[j]));
					}
				}

				// 큐 크기 * 2가 현재 열 최대크기보다 클때 전체 열 리사이징
				if (num.size() * 2 > colSize)
				{
					colSize = num.size() * 2;

					A.resize(colSize, vector<int>(rowSize));
				}

				// 큐 크기 * 2가 현재 열 최대크기보다 작을때
				// 큐 크기 * 2부터 현재 열 최대크기까지 0으로 초기화
				if (num.size() * 2 < colSize)
				{
					for (int j = num.size() * 2; j < colSize; j++)
					{
						A[j][i] = 0;
					}
				}

				// 열 크기가 100을 넘어가는 경우 처음 100개를 제외한 나머지는 버림
				if (colSize > 100)
				{
					// 우선순위 큐에서 하나씩 꺼내서 저장
					for (int j = 0; j < 100; j += 2)
					{
						if (!num.empty())
						{
							A[j][i] = num.top().number;
							A[j + 1][i] = num.top().count;
							num.pop();
						}
					}
				}
				else
				{
					// 우선순위 큐에서 하나씩 꺼내서 저장
					for (int j = 0; j < colSize; j += 2)
					{
						if (!num.empty())
						{
							A[j][i] = num.top().number;
							A[j + 1][i] = num.top().count;
							num.pop();
						}
					}
				}

				// 큐 초기화
				while (!num.empty())
				{
					num.pop();
				}

				// 카운트 배열 초기화
				for (int j = 1; j < cnt.size(); j++)
				{
					cnt[j] = 0;
				}
			}
		}
	}

	// 100초가 지나도 A[r][c] == k가 되지 않으면 -1 출력
	cout << -1 << '\n';

	return 0;
}