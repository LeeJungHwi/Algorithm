#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
using namespace std;

// ��ȭ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<int> students(n + 1); // �л� ����
	vector<int> firstDisruptor(n + 1); // �� �л��� ���� ������ ����
	stack<int> s; // ���� ������ ã���

	int height; // �л� Ű

	for (int i = 1; i < n + 1; i++)
	{
		cin >> height;

		students[i] = height; // 54 52 57 50 52 53 51
	}
	
	// ������ �л����� ���鼭
	// ������ ��ų� ���� top �л� >= i��° �л� �϶� ����
	// ���� top �л��� ���� �����ڴ� i��° �л��� Ű�� ���� �� pop
	// i��° �л� Ű ���ÿ� ����

	// 51 push
	// 51 < 53 -> while ���� -> 51�� ���ʹ����ڴ� 53�� �ε��� -> 6
	// 51 pop �� 53 push
	// 53 > 52
	// 52 push
	// 52 > 50
	// 50 push
	// 50 < 57 -> while ���� -> 50�� ���� �����ڴ� 57�� �ε��� -> 3
	// 50 pop
	// 52 < 57 -> while ���� -> 52�� ���� �����ڴ� 57�� �ε��� -> 3
	// 52 pop
	// 53 < 57 -> while ���� -> 53�� ���� �����ڴ� 57�� �ε��� -> 3
	// 53 pop �� 57 push
	// 57 > 52
	// 52 push
	// 52 < 54 -> while ���� -> 52�� ���� �����ڴ� 54�� �ε��� -> 1
	// 52 pop �� 54 push
	// 0���� �ʱ�ȭ �Ǿ����Ƿ� ���� �����ڰ� ���ų� ù��° �л��� 0

	for (int i = n; i > 0; i--)
	{
		while (!s.empty() && students[s.top()] < students[i])
		{
			firstDisruptor[s.top()] = i;
			s.pop();
		}

		s.push(i);
	}

	for (int i = 1; i < n + 1; i++)
	{
		cout << firstDisruptor[i] << ' ';
	}

	return 0;
}