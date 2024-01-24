#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���������� ���
// A�� �̱�°��
// A    B
// ���� ��
// ���� ����
// ��   ����
void ResultRockPaperScissors(vector<int> &a, vector<int> &b, int count)
{
	for (int i = 0; i < count; i++) // ���������� Ƚ����ŭ ���鼭
	{
		if (a[i] == b[i]) // ���°��
		{
			cout << "D\n";
			continue;
		}

		switch (a[i]) // ���а� �����Ǵ°��
		{
			case 1: // A�� �����϶�
				if (b[i] == 3)
				{
					cout << "A\n";
					break;
				}
				cout << "B\n";
				break;
			case 2: // A�� �����϶�
				if (b[i] == 1)
				{
					cout << "A\n";
					break;
				}
				cout << "B\n";
				break;
			case 3: // A�� ���϶�
				if (b[i] == 2)
				{
					cout << "A\n";
					break;
				}
				cout << "B\n";
				break;
		}
	}
}

// ����������
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> aRockPaperScissors(101); // A ���������� 
	vector<int> bRockPaperScissors(101); // B ����������
	int rockPaperScissors; // ����������

	// A, B ���������� ����
	for (int i = 0; i < n; i++)
	{
		cin >> rockPaperScissors;
		aRockPaperScissors[i] = rockPaperScissors;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> rockPaperScissors;
		bRockPaperScissors[i] = rockPaperScissors;
	}

	ResultRockPaperScissors(aRockPaperScissors, bRockPaperScissors, n);

	return 0;
}