#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// ���ֱ��ϱ�(ť)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	queue<int> princes; // ���ڵ� ����

	for (int i = 0; i < n; i++)
	{
		princes.push(i); // 0 1 2 3 4 5 6 7
	}

	while (princes.size() != 1) // ť�� ���ڰ� �Ѹ����� ����
	{
		// front�� push pop k - 1��
		// front�� pop 1��

		for (int i = 0; i < k - 1; i++)
		{
			princes.push(princes.front());
			princes.pop();
		}

		princes.pop();
	}

	cout << princes.front() + 1 << '\n';

	return 0;
}