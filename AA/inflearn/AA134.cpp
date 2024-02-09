#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int l, n; // L, N 6, 4
vector<pair<int, int> > pipes(20); // ������ : (����,�뷮) �� ����
vector<bool> vis(20); // �湮üũ
int maxCap; // �ۼ����� �ִ�뷮 : �������� �ۼ����� �뷮�� �ۼ����� �����ϴ� ������ �� ���� ���� �������� �뷮�̶���

void DFS(int L, int pipeLen)
{
	if (L == n || pipeLen == l) // �������� : ������ ���� �Ѿ�ų� ���� l�� �������� ������
	{
		// ������ ���� �ѱ��� ���̰� l�� �������� �����찡 �ƴϸ� ����
		if (L == n)
		{
			if (pipeLen != l)
			{
				return;
			}
		}

		// ���� ���� �������� �뷮 ����
		int minPipeCap = 2147000000;

		for (int i = 0; i < n; i++)
		{
			if (vis[i])
			{
				if (minPipeCap > pipes[i].second)
				{
					minPipeCap = pipes[i].second;
				}
			}
		}

		// �ۼ����� �ִ�뷮 ����
		if (maxCap < minPipeCap)
		{
			maxCap = minPipeCap;
		}
	}
	else
	{
		vis[L] = true; // �������� ������
		DFS(L + 1, pipeLen += pipes[L].first); // ������ �������� ���� ����
		vis[L] = false; // �������� �� ������
		DFS(L + 1, pipeLen -= pipes[L].first); // ������ �������� ���� �ٽ� ����
	}
}

// �縷�� �����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> l >> n;

	int len; // ����
	int cap; // �뷮

	//	3 6
	//	2 7
	//	4 8
	//	1 5
	for (int i = 0; i < n; i++)
	{
		cin >> len >> cap;

		pipes[i] = { len, cap };
	}

	// DFS
	DFS(0, 0);

	cout << maxCap;

	return 0;
}