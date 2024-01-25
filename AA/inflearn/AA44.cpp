#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 마구간 정하기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, c; // N, C
	cin >> n >> c;

	int xi; // 마구간 좌표
	vector<int> xiVec(n); // 마구간 좌표 저장

	for (int i = 0; i < n; i++)
	{
		cin >> xi;
		xiVec[i] = xi; // 1 2 8 4 9
	}

	sort(xiVec.begin(), xiVec.end()); // 1 2 4 8 9

	int first = xiVec[0]; // 처음
	int last = xiVec[n - 1]; // 마지막

	// 각 말 사이 거리가 될수있는 범위는 1 ~ 9
	// first standard last
	// 1     5        9
	// 각 말 사이 거리는 5 이상이어야함
	// 첫번째 말을 1에 놓고 다음 좌표에서 1을 빼면서 5이상이 되는 지점인 8에 두번째 말 놓기
	// 두번째 말부터 다음 좌표에서 1을 빼면서 5이상이 되는 지점이 없으므로 5는 아님
	// 1     2        4
	// 각 말 사이 거리는 2 이상이어야함
	// 첫번째 말을 1에 놓고 다음 좌표에서 1을 빼면서 2이상이 되는 지점인 4에 두번째 말 놓기
	// 두번째 말부터 다음 좌표에서 1을 빼면서 2이상이 되는 지점인 8에 세번째 말 놓기
	// 세번째 말을 놓았으므로 2는 가능
	// 3     3        4
	// 각 말 사이 거리는 3 이상이어야함
	// 첫번째 말을 1에 놓고 다음 좌표에서 1을 빼면서 3이상이 되는 지점인 4에 두번째 말 놓기
	// 두번째 말부터 다음 좌표에서 1을 빼면서 2이상이 되는 지점인 8에 세번째 말 놓기
	// 세번째 말을 놓았으므로 3은 가능
	// 3이 2보다 크므로 최대값 갱신
	// 4    4         4
	// 각 말 사이 거리는 4 이상이어야함
	// 첫번째 말을 1에 놓고 다음 좌표에서 1을 빼면서 4이상이 되는 지점인 8에 두번째 말 놓기
	// 두번째 말부터 다음 좌표에서 1을 빼면서 4이상이 되는 지점이 없으므로 4는 아님
	// 4    >         3
	// first와 last가 역전되었으므로 종료

	int maxCloseDis = 0; // 두 말 사이 거리의 최대

	while (first <= last) // first와 last가 역전되면 종료
	{
		int standard = (first + last) / 2; // 각 말 사이 거리는 standard 이상이어야함
		int horseIndex = 0; // 말이 배치된 인덱스
		int horseCnt = 1; // 배치된 말의 수 : 첫 인덱스에 이미 한마리 배치된 상태

		// 1 2 4 8 9
		for (int i = 1; i < n; i++)
		{
			if (xiVec[i] - xiVec[horseIndex] >= standard) // 말 사이 거리가 standard 이상이면
			{
				horseIndex = i; // 다음말 배치
				horseCnt++;

				if (horseCnt == c) // 세번째 말 배치했으면 더이상 배치할필요없음
				{
					break;
				}
			}
		}

		//cout << horseCnt << '\n';

		if (horseCnt == c) // 가능한 경우
		{
			first = standard + 1;

			if (maxCloseDis < standard) // 최대 거리 갱신
			{
				maxCloseDis = standard;
			}
		}
		else // 불가능한 경우
		{
			last = standard - 1;
		}
	}

	cout << maxCloseDis << '\n';

	return 0;
}
// 핵심
// 이진탐색 문제는 first last 범위를 잘 파악
// 첫 인덱스에 이미 한마리 배치된 상태이므로 1로 초기화