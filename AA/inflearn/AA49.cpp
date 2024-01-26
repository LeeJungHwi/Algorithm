#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// ����� �ִ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<vector<int> > frontAndAspect(2, vector<int>(n)); // ���� �� ���������鿡�� �� ���� ����
	vector<vector<int> > topdown(n, vector<int>(n)); // ������ �� ����

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> frontAndAspect[i][j];
		}
	}

	// ������ �� ����
	// 0 0 0 0
	// 0 0 0 0
	// 0 0 0 0
	// 0 0 0 0
	
	// ���� �� ���鿡�� �� ����
	// 2 0 3 1
	// 1 1 2 3

	//		  3 i
	//		  2
	//		  1
	//		  1
	// 2 0 3 1  
	// j

	// ������ �� ���� ä���
	// ��� ���� �׾����� �����ϴ� ���� ������
	// ��� ���� ���ϱ�
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