#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 1. ���� ��� ���� �Լ�
void RoundResult(vector<int> &a, vector<int> &b, vector<char> &roundRes)
{
	for (int i = 0; i < 10; i++) // �� 10����
	{
		if (a[i] > b[i]) // A�� �̱�°��
		{
			roundRes[i] = 'A';
		}
		else if (a[i] < b[i]) // B�� �̱�°��
		{
			roundRes[i] = 'B';
		}
		else if (a[i] == b[i]) // ���°��
		{
			roundRes[i] = 'D';
		}
	}
}

// 2. A, B ���� �ջ� ���� �Լ�
void SumPoint(vector<char> &roundRes, int &a, int &b, char &lastWin)
{
	for (int i = 0; i < 10; i++) // �� 10����
	{
		if (roundRes[i] == 'A') // A�� �̱����
		{
			a += 3;
			lastWin = 'A';
		}
		else if (roundRes[i] == 'B') // B�� �̱����
		{
			b += 3;
			lastWin = 'B';
		}
		else if (roundRes[i] == 'D') // ������
		{
			a += 1;
			b += 1;
		}
	}
}

// 3. ���� ��� ���� �Լ�
void FinalResult(int &a, int &b, char &lastWin)
{
	cout << a << ' ' << b << '\n';

	if (a > b) // A ������ �������
	{
		cout << 'A' << '\n';
	}
	else if (a < b) // B ������ �������
	{
		cout << 'B' << '\n';
	}
	else if (a == b) // ������ ������� -> ���� ���ų� ���� ������ ���� ���
	{
		if (lastWin == 'D') // ���� �����
		{
			cout << 'D' << '\n';
			return;
		}

		cout << lastWin << '\n'; // ���� ������ �������
	}
}

// ī�����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int num; // ����

	vector<int> aNum(10, 0), bNum(10, 0); // A, B ���� ����
	
	vector<char> roundResult(10, 0); // ���� ���

	int aSum = 0, bSum = 0; // A, B ���� ��

	char lastWinner = 'D'; // �������� �̱���

	// A, B ���� ����
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		aNum[i] = num;
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		bNum[i] = num;
	}

	// 1. ���� ��� ���� �Լ�
	// 2. A, B ���� �ջ� �Լ�
	// 3. ���� ��� ���� �Լ�
	RoundResult(aNum, bNum, roundResult);
	SumPoint(roundResult, aSum, bSum, lastWinner);
	FinalResult(aSum, bSum, lastWinner);

	return 0;
}