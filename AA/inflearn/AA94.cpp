#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���ٸ� �ǳʱ�(bottomUp)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // 7
	cin >> n;

	vector<int> caseCnt(n + 2);

	// ���ٸ� 1���� �ǳʴ� ��� : 1����
	// ���ٸ� 2���� �ǳʴ� ��� : 1 + 1, 2 -> 2����
	// ���ٸ� 3���� �ǳʴ� ��� : ���ٸ� 2�� + ���ٸ� 1�� -> 3����
	// f(n) = f(n-2) + f(n-1)
	// ���ٸ��� 7�� �̹Ƿ� ���������� n+1
	caseCnt[1] = 1;
	caseCnt[2] = 2;

	for (int i = 3; i < n + 2; i++)
	{
		caseCnt[i] = caseCnt[i - 2] + caseCnt[i - 1];
	}

	cout << caseCnt[n + 1] << '\n';

	return 0;
}