#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

long long n, p, q; // N, P, Q 7, 2, 3
map<long long, long long> m; // (Ai에서 i, 값)

// Ai 구하는 함수
long long GetAi(long long i)
{
	if (i == 0 || i == 1 || m[i] > 0) // A[0] = 1, A[1] = 2, m[i]를 이미 구한적이있으면 리턴
	{
		return m[i];
	}
	else // m[i] = m[i/p]  + m[i/q]
	{
		return m[i] = GetAi(i / p) + GetAi(i / q);
	}
}

// 무한수열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> p >> q;

	/*
	A0 = 1
	A1 = A0 + A0 = 2
	m[i]를 전에 구한적이있으면 m[i] 리턴

	A7 = A3 + A2 = 4 + 3 = 7
	A3 = A1 + A1 = 2 + 2 = 4
	A2 = A1 + A0 = 2 + 1 = 3
	*/

	m[0] = 1;
	m[1] = 2;

	cout << GetAi(n);

	return 0;
}