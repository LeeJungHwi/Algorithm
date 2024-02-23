#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

// 공 구조체
struct Ball
{
	int num; // 공 번호
	int size; // 공 크기
	int color; // 공이 속한 색

	Ball(int n, int s, int c) : num(n), size(s), color(c) {} // 생성자

	bool operator<(const Ball &ball) const // 공 크기 오름차순 정렬
	{
		return size < ball.size;
	}
};

// 컬러볼
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N, 4
	cin >> n;

	long long sumSize = 0; // 얻는점수 누적
	vector<Ball> ball; // 공 정보 저장
	map<int, long long> color; // 현재까지 잡힌 각 색의 공 크기
	vector<long long> score(n); // 자기 공으로 얻는 점수 저장

	//Input
	//	1 10
	//	3 15
	//	1 3
	//	4 8

	int c; // 색
	int s; // 크기

	for (int i = 0; i < n; i++)
	{
		cin >> c >> s;
		ball.push_back(Ball(i, s, c ));
	}

	//공 크기 기준 오름차순 정렬 nlogn
	//num size color
	// 2  3   1
	// 3  8   4
	// 0  10  1
	// 1  15  3
	sort(ball.begin(), ball.end());

	int j = 0; // j가 i를 따라감

	for (int i = 1; i < n; i++) // 공 크기가 가장낮은 공은 얻는점수가 없으므로 i가 1부터 돌면서
	{
		for (; j < n; j++) // j로 쭉 따라가면서
		{
			if (ball[i].size > ball[j].size) // i보다 크기가 작으면
			{
				sumSize += ball[j].size; // j가 잡혀서 점수 누적
				color[ball[j].color] += ball[j].size; // 현재까지 잡힌 j색 점수 누적

				continue;
			}

			// i 자기보다 크지 않으면 break
			break;
		}

		// 각 공으로 얻는 점수 = 자기보다 크기가 낮은공을 잡아서 얻은 점수 - 현재까지 자기가 속한 색의 공을 잡아 얻은 점수
		score[ball[i].num] = sumSize - color[ball[i].color];
	}

	// 각 공으로 얻는 점수 출력
	for (int i = 0; i < n; i++)
	{
		cout << score[i] << "\n";
	}

	return 0;
}