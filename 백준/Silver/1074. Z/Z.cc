#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <fstream>
using namespace std;

// 좌상 우상 좌하 우하 순서로 방문
int Z(int n, int r, int c)
{
	// 종료조건 : n이 0인 경우 현재위치 리턴
	if (n == 0)
	{
		return n;
	}

	// 현재 구역크기 구하기
	int size = pow(2, n - 1); // 2^(n-1)

	// 좌상 우상 좌하 우하 순서로 방문 

	if (r < size && c < size) // 좌상
	{
		return Z(n - 1, r, c); // 좌상 방문값 // 0 * 4^(n-1) + Z
	}

	if (r < size && c >= size) // 우상
	{
		return size * size + Z(n - 1, r, c - size); // 1 * 4^(n-1) + Z
	}

	if (r >= size && c < size) // 좌하
	{
		return 2 * size * size + Z(n - 1, r - size, c); // 2 * 4^(n-1) + Z 
	}

	// 우하
	return 3 * size * size + Z(n - 1, r - size, c - size); // 3 * 4^(n-1) + Z
}

// Z
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, r, c; // N, R, C 2, 3, 1
	cin >> n >> r >> c;

	// 방문값
	// n 1 : 0 1 2 3
	// n 2 : 0 4 8 12
	// n 3 : 0 16 32 48
	// n 4 : 0 64 128 192
	// n 5 : 0 1 * 4^(n-1) 2 * 4^(n-1) 3 * 4^(n-1)

	// 구역값
	// n 1 : (0,0) (0,1) (1,0) (1,1) 각 점으로부터 1by1
	// n 2 : (0,0) (0,2) (2,0) (2,2) 각 점으로부터 2by2
	// n 3 : (0,0) (0,4) (4,0) (4,4) 각 점으로부터 4by4
	// n 4 : (0,0) (0,8) (8,0) (8,8) 각 점으로부터 8by8
	// n 5 : (0,0) (0,2^(n-1)) (2^(n-1),0) (2^(n-1),2^(n-1)) 각 점으로부터 2^(n-1)by2^(n-1)
	// 구역크기 : 2^(n-1)

	// (r,c)를 몇번째에 방문하는지 구하기

	cout << Z(n, r, c) << '\n';

	return 0;
}
