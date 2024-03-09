#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 해당 위치에 별을 찍을지 선택 
void PrintStar(int i, int j, int n)
{
	// 가운데 없음
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
	{
		cout << ' ';
	}
	else // 가운데 있음 
	{
		// 기본패턴
		if (n / 3 == 0)
		{
			cout << '*';
		}
		else // 이전패턴
		{
			PrintStar(i, j, n / 3);
		}
	}
}

// 패턴출력
void PrintPattern(int n)
{
	// 그래프 돌면서 별찍기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			PrintStar(i, j, n);
		}

		cout << '\n';
	}
}

// 별찍기 10
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 27
	cin >> n;

	// n 3 : 가운데 * 없음
	// n 9 : 가운데 n 3 없음
	// n 27 : 가운데 n 9 없음
	// n 3^k : 가운데 n 3^(k-1) 없음

	PrintPattern(n);

	return 0;
}
