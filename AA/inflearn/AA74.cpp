#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// �ּ���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	priority_queue<int, vector<int>, greater<int>> minHeap; // ť�� front�� �M -> �������� ����

	int num; // ����

	while (true)
	{
		cin >> num;

		if (num == -1) // -1 �Է½� ����
		{
			return 0;
		}
		
		if (num != 0) // 0�� �ƴϸ� �ּ����� push
		{
			minHeap.push(num);
		}
		else // 0 �Է½� �ּҰ� ���, ť�� ������� -1 ���
		{
			if (minHeap.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << minHeap.top() << '\n';
				minHeap.pop();
			}
		}
	}
}
// �ٽ�
// �ּ��� : �������� ����
// push �Ҷ� -num�� push�ϸ� �������� ��Ʈ�� ���Եǰ� ��½� -minHeap.top()�� ����ϸ� �ּ����� ������