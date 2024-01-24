#include <iostream>
#include <fstream>
using namespace std;

// 층간소음
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N초 M값
	cin >> n >> m;

	int noise; // 측정치
	int time = 0; // 경보음 시간
	int maxTime = 0; // 최대 경보음 시간

	// 최대 연속 경보음 구하기
	for (int i = 0; i < n; i++)
	{
		cin >> noise;

		if (noise > m) // M값을 넘으면 경보음 시간 증가
		{
			time++;

			if (time > maxTime) // 최대 경보음 시간 갱신
			{
				maxTime = time;
			}
		}
		else // 아니면 시간 초기화
		{
			time = 0;
		}
	}

	cout << maxTime << '\n';

	return 0;
}