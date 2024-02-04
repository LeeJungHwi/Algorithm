#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// ��۸�����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 1500
	cin >> n;

	vector<int> uglyNums(n + 1); // �ε��� ��° ��۸����� ����

	// uglyNums �ε����� ����Ű�� ������
	// p2, p3, p5 ��� 1�� �ʱ�ȭ
	// p2, p3, p5 ���� 2, 3, 5�� ���ϰ� �ּҰ��� ��۸����ڷ� ����
	// �ּҰ��� ���� �����ʹ� 1 �������� ���� �ε����� ����Ű����
	/*
	1 1 1
	2 3 5 -> �ּҰ� 2, p2 1����
	2 1 1
	4 3 5 -> �ּҰ� 3, p3 1����
	2 3 1
	4 9 5 -> �ּҰ� 4, p2 1����
	4 3 1
	8 9 5 -> �ּҰ� 5, p3 1����
	....
	*/
	int p2 = 1;
	int p3 = 1;
	int p5 = 1;

	// �ּҰ�
	int minNum = 0;

	// 1�� ù��° ��۸�����
	uglyNums[1] = 1;

	for (int i = 2; i < n + 1; i++) // �ι�° ��۸����� ���� ã��
	{
		// p2, p3, p5 ���� 2, 3, 5�� ���ϰ� �ּҰ� ã��
		if (uglyNums[p2] * 2 < uglyNums[p3] * 3)
		{
			minNum = uglyNums[p2] * 2;
		}
		else
		{
			minNum = uglyNums[p3] * 3;
		}

		if (uglyNums[p5] * 5 < minNum)
		{
			minNum = uglyNums[p5] * 5;
		}

		// �ּҰ��� ���� �����ʹ� 1 �������� ���� �ε����� ����Ű����
		if (minNum == uglyNums[p2] * 2)
		{
			p2++;
		}

		if (minNum == uglyNums[p3] * 3)
		{
			p3++;
		}

		if (minNum == uglyNums[p5] * 5)
		{
			p5++;
		}

		// ��۸����� ����
		uglyNums[i] = minNum;
	}

	cout << uglyNums[n] << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//// ��۸� ����
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n; // N 10
//	cin >> n;
//
//	int uglyNumCnt = 1; // ��۸� ���� ����
//	int curNum = 2; // ��۸� �������� üũ�� ����
//
//	if (n == 1) // ù��° ��۸� ���ڴ� 1
//	{
//		cout << 1 << '\n';
//
//		return 0;
//	}
//	else // �ι�° ��۸� ���ں��ʹ�
//	{
//		while (uglyNumCnt < n) // n��° ��۸� ���ڰ� �Ǹ� ����
//		{
//			int i = curNum;
//
//			// 2�� ���������� �������� 0�� �ƴҶ����� ������
//			while (i % 2 == 0)
//			{
//				i /= 2;
//			}
//
//			// 3���� ���������� �������� 0�� �ƴҶ����� ������
//			while (i % 3 == 0)
//			{
//				i /= 3;
//			}
//
//			// 5�� ���������� �������� 0�� �ƴҶ����� ������
//			while (i % 5 == 0)
//			{
//				i /= 5;
//			}
//
//			// i�� 1�̸� ��۸� ����
//			if (i == 1)
//			{
//				uglyNumCnt++;
//			}
//
//			// üũ�� ���� ����
//			curNum++;
//		}
//	}
//
//	cout << curNum - 1 << '\n';
//
//	return 0;
//}