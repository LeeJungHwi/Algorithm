#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 오렌지나무
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int w, h, t, s; // W, H, T, S 10, 9, 8, 3
	cin >> w >> h >> t >> s;

	vector<int> x, y; // 오렌지나무 좌표 저장

	int orangeX, orangeY; // 오렌지나무 좌표

	/*
	input : 3 4
			6 3
			5 7
			6 6
			9 5
			6 9
			7 8
			8 9

	x	: 3 6 5 6 9 6 7 8

	y	: 4 3 7 6 5 9 8 9
	*/

	for (int i = 0; i < t; i++)
	{
		cin >> orangeX >> orangeY;
		x.push_back(orangeX);
		y.push_back(orangeY);
	}

	// 오렌지나무 최대개수 구하기

	int maxOrangeCnt = 0; // 오렌지나무 최대개수

	for (int i = 0; i < t; i++) // i로 x 접근
	{
		for (int j = 0; j < t; j++) // j로 y 접근
		{
			// 정사각형 왼하 좌표가 정해짐 (i, j)

			int orangeCnt = 0; // 오렌지나무 개수

			for (int k = 0; k < t; k++) // 오렌지나무가
			{
				if (x[k] + 1 > x[i] && x[k] < x[i] + s + 1) // 정사각형 x 범위에 있고
				{
					if (y[k] + 1 > y[j] && y[k] < y[j] + s + 1) // 정사각형 y 범위에 있으면
					{
						orangeCnt++; // 오렌지나무가 영역 안에 있으므로 카운팅
					}
				}
			}

			maxOrangeCnt = max(maxOrangeCnt, orangeCnt); // 오렌지나무 최대개수 갱신
		}
	}

	cout << maxOrangeCnt << '\n';

	return 0;
}
// 핵심
// 인접행렬 그래프 브루트포스 -> 시간초과 -> 인접행렬 그래프 DP -> 시간초과 -> 정사각형 영역으로 가능한 경우의 수 브루트포스로 해결

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// 오렌지나무
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int w, h, t, s; // W, H, T, S 10, 9, 8, 3
//	cin >> w >> h >> t >> s;
//
//	vector<vector<int > > graph(h + 1, vector<int>(w + 1)); // 그래프
//
//	int orangeX, orangeY; // 오렌지나무 좌표
//
//	/*
//	input : 3 4
//			6 3
//			5 7
//			6 6
//			9 5
//			6 9
//			7 8
//			8 9
//
//	graph : 0 0 0 0 0 0 0 0 0 0
//			0 0 0 0 0 0 0 0 0 0
//			0 0 0 0 0 1 0 0 0 0
//			0 0 1 0 0 0 0 0 0 0
//			0 0 0 0 0 0 0 0 1 0
//			0 0 0 0 0 1 0 0 0 0
//			0 0 0 0 1 0 0 0 0 0
//			0 0 0 0 0 0 1 0 0 0
//			0 0 0 0 0 1 0 1 0 0
//	*/
//	for (int i = 0; i < t; i++)
//	{
//		cin >> orangeX >> orangeY;
//
//		graph[orangeY][orangeX] = 1;
//	}
//
//	// 현수가 얻을 수 있는 오렌지나무 최대개수 구하기
//
//	int maxOrangeCnt = 0; // 최대 오렌지나무 개수
//
//	for (int i = 1; i < h - s + 1; i++)
//	{
//		for (int j = 1; j < w - s + 1; j++)
//		{
//			int orangeCnt = 0; // 오렌지나무 개수
//
//			for (int l = i; l < i + s + 1; l++) // 현수가 하사받은 영역 내 오렌지나무 개수 카운팅
//			{
//				for (int m = j; m < j + s + 1; m++)
//				{
//					if (graph[l][m] == 1)
//					{
//						orangeCnt++;
//					}
//				}
//			}
//
//			if (maxOrangeCnt < orangeCnt) // 최대 오렌지나무 개수 갱신
//			{
//				maxOrangeCnt = orangeCnt;
//			}
//		}
//	}
//
//	cout << maxOrangeCnt << '\n';
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// 오렌지나무
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int w, h, t, s; // W, H, T, S 10, 9, 8, 3
//	cin >> w >> h >> t >> s;
//
//	vector<vector<int > > graph(h + 1, vector<int>(w + 1)); // 그래프
//	vector<vector<int > > orangeCnts(h + 1, vector<int>(w + 1)); // 오렌지나무 개수 저장
//
//	int orangeX, orangeY; // 오렌지나무 좌표
//
//	/*
//	input : 3 4
//			6 3
//			5 7
//			6 6
//			9 5
//			6 9
//			7 8
//			8 9
//
//	graph : 0 0 0 0 0 0 0 0 0 0
//			0 0 0 0 0 0 0 0 0 0
//			0 0 0 0 0 1 0 0 0 0
//			0 0 1 0 0 0 0 0 0 0
//			0 0 0 0 0 0 0 0 1 0
//			0 0 0 0 0 1 0 0 0 0
//			0 0 0 0 1 0 0 0 0 0
//			0 0 0 0 0 0 1 0 0 0
//			0 0 0 0 0 1 0 1 0 0
//	*/
//	for (int i = 0; i < t; i++)
//	{
//		cin >> orangeX >> orangeY;
//
//		graph[orangeY][orangeX] = 1;
//	}
//
//	// DP로 (1,1)에서 본인좌표까지 오렌지나무 개수 저장 : orangeCnts[i][j] = orangeCnts[i - 1][j] + orangeCnts[i][j - 1] - orangeCnts[i - 1][j - 1] + graph[i][j]
//	for (int i = 1; i < h + 1; i++)
//	{
//		for (int j = 1; j < w + 1; j++)
//		{
//			orangeCnts[i][j] = orangeCnts[i - 1][j] + orangeCnts[i][j - 1] - orangeCnts[i - 1][j - 1] + graph[i][j];
//		}
//	}
//
//	// 현수가 하사받은 영역 중 오렌지나무 최대개수 구하기 : orangeCnt = orangeCnts[i][j] - orangeCnts[i - s - 1][j] - orangeCnts[i][j - s - 1] + orangeCnts[i - s - 1][j - s - 1]
//
//	int orangeCnt = 0; // 각 하사받은 땅의 오렌지나무 개수
//	int maxOrangeCnt = 0; // 최대 오렌지나무 개수
//
//	for (int i = s + 1; i < h + 1; i++)
//	{
//		for (int j = s + 1; j < w + 1; j++)
//		{
//			orangeCnt = orangeCnts[i][j] - orangeCnts[i - s - 1][j] - orangeCnts[i][j - s - 1] + orangeCnts[i - s - 1][j - s - 1];
//
//			if (maxOrangeCnt < orangeCnt)
//			{
//				maxOrangeCnt = orangeCnt;
//			}
//		}
//	}
//
//	cout << maxOrangeCnt << '\n';
//
//	return 0;
//}

