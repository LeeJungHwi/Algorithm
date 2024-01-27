#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

// ��������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> trainOrder(n); // ���� ����
	int curArrive = 1; // ���� �����ؾ��ϴ� ���� ��ȣ
	stack<int> crossRoad; // ������
	queue<char> processOrder; // �۾� ����
	
	// ���� ��ȣ ������� �����ϰ��ϱ�
	// push�ϸ� ť�� P ���� pop�ϸ� ť�� O ����
	// ���� �����ؾ��ϴ� ������ȣ���� push
	// ���� �����ؾ��ϴ� ������ȣ pop
	// ���� ž�� ���絵���ؾ��ϴ� ������ȣ�� üũ�ϸ鼭 pop �Ǵ� ����
	// ���ÿ� ������ �����ִٸ� �Ұ����ϹǷ� impossible ���
	// ������ ����ִٸ� ���������ϹǷ� ť ���
	for (int i = 0; i < n; i++)
	{
		cin >> trainOrder[i]; // 2 1 3
	}

	for (int i = 0; i < n; i++)
	{
		if (trainOrder[i] != curArrive) // ���� �����ؾ��ϴ� ������ȣ ������ push
		{
			crossRoad.push(trainOrder[i]);
			processOrder.push('P');
		}
		else // ���� �����ؾ��ϴ� ������ȣ���
		{
			// ���� �����ؾ��ϴ� ���� push
			crossRoad.push(trainOrder[i]);
			processOrder.push('P');

			// ���� �����ؾ��ϴ� ���� pop
			crossRoad.pop();
			processOrder.push('O');
			curArrive++;

			// ������ ž�� ���� �����ؾ��ϴ� ������ȣ�� �ƴҶ����� pop
			while(!crossRoad.empty())
			{
				if(crossRoad.top() == curArrive)
				{
					crossRoad.pop();
					processOrder.push('O');
					curArrive++;
				}
				else // ���� �����ؾ��ϴ� ������ȣ�� �ƴϸ� ����
				{
					break;
				}
			}
		}
	}

	if (!crossRoad.empty()) // ���ÿ� ������ �����ִٸ� �Ұ���
	{
		cout << "impossible";
	}
	else // ������ ����ִٸ� ��������
	{
		while (!processOrder.empty())
		{
			cout << processOrder.front();
			processOrder.pop();
		}
	}

	return 0;
}
// �ٽ�
// ť push : ť �ڿ� ��� ����
// ť pop : ť �� ��� ����