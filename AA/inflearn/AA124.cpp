#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // N 3
char s[20]; // ��ȣ���ڿ�
int cnt; // ��ȣ���ڿ� ����

// DFS
void DFS(int L, int open, int close)
{
	if (L == n * 2) // �������� : ��ȣ�� n * 2�� ������ ���
	{
		// ��ȣ���ڿ� ���
		cout << s << '\n';

		// ��ȣ���ڿ� ���� ����
		cnt++;
	}
	else
	{
		// ���� ��ȣ�� �߰��� �� �ִ� ��� : ���� ���°�ȣ ������ ��ü ���°�ȣ �������� ������
		if (open < n)
		{
			s[L] = '(';
			DFS(L + 1, open + 1, close);
		}

		// �ݴ� ��ȣ�� �߰��� �� �ִ� ��� : ���� �ݴ°�ȣ ������ ���� ���°�ȣ �������� ������
		if (close < open)
		{
			s[L] = ')';
			DFS(L + 1, open, close + 1);
		}
	}
}

// ��� ���� ��ȣ
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	// DFS
	DFS(0, 0, 0);

	cout << cnt;

	return 0;
}
