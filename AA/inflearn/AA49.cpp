#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 블록의 최댓값
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<vector<int> > frontAndAspect(2, vector<int>(n)); // 정면 및 오른쪽측면에서 본 높이 저장
	vector<vector<int> > topdown(n, vector<int>(n)); // 위에서 본 높이

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> frontAndAspect[i][j];
		}
	}

	// 위에서 본 높이
	// 0 0 0 0
	// 0 0 0 0
	// 0 0 0 0
	// 0 0 0 0
	
	// 정면 및 측면에서 본 높이
	// 2 0 3 1
	// 1 1 2 3

	//		  3 i
	//		  2
	//		  1
	//		  1
	// 2 0 3 1  
	// j

	// 위에서 본 높이 채우기
	// 행렬 직선 그엇을때 교차하는 값중 작은값
	// 블록 총합 구하기
	int blockCnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			topdown[i][j] = min(frontAndAspect[1][n - i - 1], frontAndAspect[0][j]);
			blockCnt += topdown[i][j];
		}
	}

	cout << blockCnt << '\n';

	return 0;
}