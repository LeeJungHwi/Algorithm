#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<int> cnts(10); // ���� �ڸ��� ī��Ʈ
int maxCnt; // ���� ���� ���� �ڸ��� ����
int maxNum; // ���� ���� ���� �ڸ���

// ���� �ڸ��� ī����
// 1230565625
// 1230565625 % 10 = 5
// 123056562 % 10 = 2
// 12305656 % 10 = 6
// ....
void CountPosNum(string num)
{
	while (!num.empty())
	{
		cnts[num.back() - '0']++; // 1�� �ڸ��� ī����
		num.pop_back(); // 1�� �ڸ��� ���� ����
	}
}

// ���� ���� ���� �ڸ���
// 1~9 ���� ������� üũ�ϹǷ� ���� ��쵵 �׳� �����ص� ��
void MaxPosNum()
{
	for (int i = 1; i < 10; i++)
	{
		if (cnts[i] >= maxCnt) // ���� Ƚ���� ���ų� ������ ����
		{
			maxCnt = cnts[i];
			maxNum = i;
		}
	}

	cout << maxNum << '\n';
}

// ���� ���� ���� �ڸ���
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string n; // N
	cin >> n;

	CountPosNum(n);
	MaxPosNum();

	return 0;
}

// �ٽ�
// ���ڰ� �ſ� ũ�ٸ� string���� �Է��� ����
// string.back() -> ������ ���� ����
// string.pop_back() -> ������ ���� ����