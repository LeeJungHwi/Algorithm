#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n;
vector<int> caseCnt(46);

int DFS(int n)
{
	if (caseCnt[n] > 0) // ���� : �̹� ������ �� ��ȯ
	{
		return caseCnt[n];
	}
	else if (n == 2)
	{
		return caseCnt[2];
	}
	else if (n == 1)
	{
		return caseCnt[1];
	}
	else
	{
		return caseCnt[n] = DFS(n - 2) + DFS(n - 1); // �޸�
	}
}

// ��Ʈ��ũ �� �ڸ���(topDown)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	caseCnt[1] = 1;
	caseCnt[2] = 2;

	DFS(n);

	cout << caseCnt[n];

	return 0;
}
// �ٽ�
// DP
/*
topDown : DFS�� �޸������̼� �̿�
*/