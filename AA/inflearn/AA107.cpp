#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ����������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int w, h, t, s; // W, H, T, S 10, 9, 8, 3
	cin >> w >> h >> t >> s;

	vector<int> x, y; // ���������� ��ǥ ����

	int orangeX, orangeY; // ���������� ��ǥ

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

	// ���������� �ִ밳�� ���ϱ�

	int maxOrangeCnt = 0; // ���������� �ִ밳��

	for (int i = 0; i < t; i++) // i�� x ����
	{
		for (int j = 0; j < t; j++) // j�� y ����
		{
			// ���簢�� ���� ��ǥ�� ������ (i, j)

			int orangeCnt = 0; // ���������� ����

			for (int k = 0; k < t; k++) // ������������
			{
				if (x[k] + 1 > x[i] && x[k] < x[i] + s + 1) // ���簢�� x ������ �ְ�
				{
					if (y[k] + 1 > y[j] && y[k] < y[j] + s + 1) // ���簢�� y ������ ������
					{
						orangeCnt++; // ������������ ���� �ȿ� �����Ƿ� ī����
					}
				}
			}

			maxOrangeCnt = max(maxOrangeCnt, orangeCnt); // ���������� �ִ밳�� ����
		}
	}

	cout << maxOrangeCnt << '\n';

	return 0;
}
// �ٽ�
// ������� �׷��� ���Ʈ���� -> �ð��ʰ� -> ������� �׷��� DP -> �ð��ʰ� -> ���簢�� �������� ������ ����� �� ���Ʈ������ �ذ�

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// ����������
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
//	vector<vector<int > > graph(h + 1, vector<int>(w + 1)); // �׷���
//
//	int orangeX, orangeY; // ���������� ��ǥ
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
//	// ������ ���� �� �ִ� ���������� �ִ밳�� ���ϱ�
//
//	int maxOrangeCnt = 0; // �ִ� ���������� ����
//
//	for (int i = 1; i < h - s + 1; i++)
//	{
//		for (int j = 1; j < w - s + 1; j++)
//		{
//			int orangeCnt = 0; // ���������� ����
//
//			for (int l = i; l < i + s + 1; l++) // ������ �ϻ���� ���� �� ���������� ���� ī����
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
//			if (maxOrangeCnt < orangeCnt) // �ִ� ���������� ���� ����
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
//// ����������
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
//	vector<vector<int > > graph(h + 1, vector<int>(w + 1)); // �׷���
//	vector<vector<int > > orangeCnts(h + 1, vector<int>(w + 1)); // ���������� ���� ����
//
//	int orangeX, orangeY; // ���������� ��ǥ
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
//	// DP�� (1,1)���� ������ǥ���� ���������� ���� ���� : orangeCnts[i][j] = orangeCnts[i - 1][j] + orangeCnts[i][j - 1] - orangeCnts[i - 1][j - 1] + graph[i][j]
//	for (int i = 1; i < h + 1; i++)
//	{
//		for (int j = 1; j < w + 1; j++)
//		{
//			orangeCnts[i][j] = orangeCnts[i - 1][j] + orangeCnts[i][j - 1] - orangeCnts[i - 1][j - 1] + graph[i][j];
//		}
//	}
//
//	// ������ �ϻ���� ���� �� ���������� �ִ밳�� ���ϱ� : orangeCnt = orangeCnts[i][j] - orangeCnts[i - s - 1][j] - orangeCnts[i][j - s - 1] + orangeCnts[i - s - 1][j - s - 1]
//
//	int orangeCnt = 0; // �� �ϻ���� ���� ���������� ����
//	int maxOrangeCnt = 0; // �ִ� ���������� ����
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

