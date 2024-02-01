#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ��Ʈ��ũ �� �ڸ���(BottomUp)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<int> caseCnt(n + 1); // �� ���̸� ������ ���� �ڸ��� ����� �� ���

	// 1m ���� �ڸ��¹�� : 1 -> 1����
	// 2m ���� �ڸ��¹�� : 1+1, 2 -> 2����
	caseCnt[1] = 1;
	caseCnt[2] = 2;

	// 3m ���� �ڸ��¹�� : ������ ���� ���̰� 1m �϶� ���� 2m�� �ڸ��� ����� 2���� + ������ ���� ���̰� 2m �϶� ���� 1m�� �ڸ��� ����� 1���� -> caseCnt[3] = caseCnt[2] + caseCnt[1] -> 3����
	// 4m ���� �ڸ��¹�� : ������ ���� ���̰� 1m �϶� ���� 3m�� �ڸ��� ����� 3���� + ������ ���� ���̰� 2m �϶� ���� 2m�� �ڸ��� ����� 2���� -> caseCnt[4] = caseCnt[3] + caseCnt[2] -> 5����
	// f(n) = f(n-2) + f(n-1)
	for (int i = 3; i < n + 1; i++)
	{
		caseCnt[i] = caseCnt[i - 2] + caseCnt[i - 1];
	}

	cout << caseCnt[n] << '\n';

	return 0;
}
// �ٽ�
// DP
/*
bottomUp : �������� �طκ��� ��ȭ���� ���� ū������ Ȯ��
*/