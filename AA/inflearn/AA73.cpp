#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

// �ִ���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	priority_queue<int> maxHeap;

	int num; // ����

	while (true)
	{
		cin >> num;

		if (num == -1) // -1 �Է½� ����
		{
			return 0;
		}

		if (num != 0) // 0�� �ƴϸ� �ڿ��� push
		{
			maxHeap.push(num);
		}
		else // 0�̸� �ִ밪 ���, ť�� ������� -1 ���
		{
			if (maxHeap.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << maxHeap.top() << '\n';
				maxHeap.pop();
			}
		}
	}
}
// �ٽ�
// �켱���� ť