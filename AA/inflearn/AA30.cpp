#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

// 3�� ������?(large)
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	// 0001
	// 0002
	// ....
	// 0130
	// 0131
	// 0132
	// ....
	// 0130
	// 0131
	// ....
	// 5367

	// �����ڸ����� 3�� ������ ����� ��
	// lt cur rt k(���� �ڸ���)
	// 53  6  7  10
	// 003(0~9) : 10��
	// 013(0~9) : 10��
	// 023(0~9) : 10��
	// ....
	// 533(0~9) : 10��
	// cur > 3 ��� (left + 1) * k = 54 * 10 = 540��
	// cur == 3 ��� (left) * k + (right + 1) = 53 * 10 + 8 = 538��
	// cur < 3 ��� (left) * k = 53 * 10 = 530��

	// õ���ڸ����� 3�� ������ ����� ��
	// lt cur rt k(���� �ڸ���)
	// 0  5  367 1000
	// 3(0~999) : 1000��
	// cur > 3 ��� (left + 1) * k = (0 + 1) * 1000 = 1000��
	// cur == 3 ��� (left) * k + (right + 1) =  0 * 1000 + 368 = 368��
	// cur < 3 ��� (left) * k = 0 * 1000 = 0��

	int left; // cur ����
	int cur; // ���� ���� �ڸ����� ����
	int right; // cur ������
	int k = 1; // 1�� �ڸ����� ����
	int threeCnt = 0; // 3�� ���� ����

	do
	{
		left = n / (k * 10); // left ���� 5367 / 10 = 536 -> 53 -> 5 -> 0
		cur = (n / k) % 10; // cur ���� 5367 % 10 = 7 -> 6 -> 3 -> 5
		right = n % k; // right ���� 5367 % 1 = 0 -> 7 -> 67 -> 367

		if (cur > 3) // cur > 3 ��� (left + 1) * k
		{
			threeCnt += (left + 1) * k;
		}
		else if (cur == 3) // cur == 3 ��� (left) * k + (right + 1)
		{
			threeCnt += left * k + (right + 1);
		}
		else if (cur < 3) // cur < 3 ��� (left) * k
		{
			threeCnt += left * k;
		}

		k *= 10; // ���� �ڸ��� ���� 1 -> 10 -> 100 -> 1000
	} while (left != 0);

	cout << threeCnt << '\n';

	return 0;
}

// �ٽ�
// �� �ڸ����� 3�� ���� üũ