#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n; // 7
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

// ��ܿ�����(topDown)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	// ��� 1�� : 1����
	// ��� 2�� : 1 + 1, 2 -> 2����
	// ��� 3�� : �������� ����� 1�� �ö󰥶� �տ� ��� 2���� �ö󰡴� ��� 2���� + �������� ����� 2�� �ö󰥶� �տ� ��� 1���� �ö󰡴� ��� 1���� -> 3����
	caseCnt[1] = 1;
	caseCnt[2] = 2;
	DFS(n);

	cout << caseCnt[n] << '\n';

	return 0;
}