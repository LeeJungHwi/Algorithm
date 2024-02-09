#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// ���ڿ� ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n1, n2, n3; // N1, N2, N3 5, -1, -3
	cin >> n1 >> n2 >> n3;

	string first; // ù��° ���ڿ� abcb
	cin >> first;

	string second; // �ι�° ���ڿ� acb
	cin >> second;

	// lengths[i][j] : ù��° ���ڿ� i��° ���̱����� �ι�° ���ڿ� j��° ���̱��� �������ִ� �ִ����� ����
	vector<vector<int> > lengths(first.size() + 1, vector<int>(second.size() + 1));

	/*
		���� a c b
	���� 0 -1 -2 -3
	a	-1
	b	-2
	c	-3
	b	-4
	*/
	for (int i = 1; i < first.size() + 1; i++)
	{
		lengths[i][0] = n2 * i;
	}

	for (int i = 1; i < second.size() + 1; i++)
	{
		lengths[0][i] = n2 * i;
	}

	/*
		���� a c b
	���� 0 -1 -2 -3
	a	-1  5  4  3
	b	-2  4  3  ?(9) : ab, acb���� ������ ���ڰ� b�� ������
	c	-3  3  9  ?max(8, 8, 1, 0) : abc, acb���� ������ ���ڰ� ���� �ٸ���
	b	-4  2  8  14
	*/
	// ������ �� ���ڰ� ���� ������ 1���� ���
	// ab, acb �Ѵٿ��� ������ ���ڸ� �����ؼ� a, ac�� �������ִ� �ִ����� 4 + �������� b ��Ī ���� 5 -> 9
	// ������ �� ���ڰ� ���� �ٸ��� 4���� ���
	// 1. acb���� ������ ���ڸ� �����ؼ� abc, ac�� �������ִ� �ִ����� 9 + �����ϰ� b ��Ī ���� -1 -> 8
	// 2. abc���� ������ ���ڸ� �����ؼ� ab, acb�� �������ִ� �ִ����� 9 + �����ϰ� c ��Ī ���� -1 -> 8
	// 3. acb, abc �Ѵٿ��� ������ ���ڸ� �����ؼ� ac, ab�� �������ִ� �ִ����� 3 + �����ϰ� b ��Ī ���� -1 + �����ϰ� c ��Ī ���� -1 -> 1
	// 4. acb, abc �Ѵٿ��� ������ ���ڸ� �����ؼ� ac, ab�� �������ִ� �ִ����� 3 + b�� c ��Ī ���� -3 -> 0
	// �� �װ��� ��� �� �ִ밪�� lengths[i][j]�� ����
	for (int i = 1; i < first.size() + 1; i++)
	{
		for (int j = 1; j < second.size() + 1; j++)
		{
			if (first[i - 1] == second[j - 1]) // �� �κй��ڿ��� ������ ���ڰ� ������
			{
				lengths[i][j] = lengths[i - 1][j - 1] + n1;
			}
			else // �� �κй��ڿ��� ������ ���ڰ� �ٸ���
			{
				int max = 0;

				// 1. 2.
				if (lengths[i - 1][j] + n2 > lengths[i][j - 1] + n2)
				{
					max = lengths[i - 1][j] + n2;
				}
				else
				{
					max = lengths[i][j - 1] + n2;
				}

				// 4.
				if (lengths[i - 1][j - 1] + n3 > max)
				{
					max = lengths[i - 1][j - 1] + n3;
				}

				// 3.
				if (lengths[i - 1][j - 1] + (n2 * 2) > max)
				{
					max = lengths[i - 1][j - 1] + (n2 * 2);
				}

				// �װ��� ��� �� �ִ밪�� lengths[i][j]�� ����
				lengths[i][j] = max;
			}
		}
	}

	cout << lengths[first.size()][second.size()];

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <fstream>
//using namespace std;
//
//// ���ڿ� ����
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	int n1, n2, n3; // N1, N2, N3 5, -1, -3
//	cin >> n1 >> n2 >> n3;
//
//	string first; // ù��° ���ڿ� abcb
//	cin >> first;
//
//	string second; // �ι�° ���ڿ� acb
//	cin >> second;
//
//	// 1. first, second�� LCS ���̸� ���ϰ� ���� += LCS���� * n1
//
//	int score = 0; // ����
//
//	vector<vector<int> > lengths(first.size() + 1, vector<int>(second.size() + 1)); // lengths[i][j] : ù��° ���ڿ� i��° ���̱����� �ι�° ���ڿ� j��° ���̱��� �ִ���빮�ڿ� ����
//
//	for (int i = 1; i < first.size() + 1; i++)
//	{
//		for (int j = 1; j < second.size() + 1; j++)
//		{
//			if (first[i - 1] == second[j - 1]) // �� �κй��ڿ��� ������ ���ڰ� ���ٸ�
//			{
//				lengths[i][j] = lengths[i - 1][j - 1] + 1; // �� �κй��ڿ��� ������ ���ڸ� �� �ִ���� + 1
//			}
//			else // �� �κй��ڿ��� ������ ���ڰ� �ٸ��ٸ�
//			{
//				lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1]); // max(ù���ڿ��� ���������� �� �ִ����, �ι�°���ڿ��� ���������� �� �ִ����)
//			}
//		}
//	}
//
//	score += n1 * lengths[first.size()][second.size()]; // LCS���� * n1
//
//	// 2. first, second���� LCS�κ��� ���鹮�ڷ� ��ü�ϱ�
//
//	int firstSize = first.size(); // ù��° ���ڿ� ũ��
//	int secondSize = second.size(); // �ι�° ���ڿ� ũ��
//
//	string lcsString = ""; // LCS ���ڿ�
//
//	while (firstSize > 0 && secondSize > 0) // LCS ���ڿ� ã�� acb
//	{
//		if (first[firstSize - 1] == second[secondSize - 1])
//		{
//			lcsString = first[firstSize - 1] + lcsString;
//			firstSize--;
//			secondSize--;
//		}
//		else if (lengths[firstSize - 1][secondSize] > lengths[firstSize][secondSize - 1])
//		{
//			firstSize--;
//		}
//		else
//		{
//			secondSize--;
//		}
//	}
//
//	int startJ = 0; // ������ j �ε���
//
//	for (int i = 0; i < lcsString.size(); i++) // ù��° ���ڿ� LCS�κ� ���鹮�ڷ� ��ü : ����b�������
//	{
//		for (int j = startJ; j < first.size(); j++)
//		{
//			if (lcsString[i] == first[j])
//			{
//				first[j] = ' ';
//				startJ = j + 1;
//				break;
//			}
//		}
//	}
//
//	startJ = 0; // ������ j �ε��� �ʱ�ȭ
//
//	for (int i = 0; i < lcsString.size(); i++) // �ι�° ���ڿ� LCS�κ� ���鹮�ڷ� ��ü : ����������
//	{
//		for (int j = startJ; j < second.size(); j++)
//		{
//			if (lcsString[i] == second[j])
//			{
//				second[j] = ' ';
//				startJ = j + 1;
//				break;
//			}
//		}
//	}
//
//	// 3. first, second�� ũ�Ⱑ ������ ���� ���ڿ��� ���鹮�� �ֱ�
//
//	if (first.size() < second.size())
//	{
//		first.append(second.size() - first.size(), ' ');
//	}
//	else if (second.size() < first.size())
//	{
//		second.append(first.size() - second.size(), ' '); // �ι�° ���ڿ� : �������������
//	}
//
//	// 4. first, second�� ���ϸ鼭 �Ѵ� �����̸� ����, �ϳ��� �����̸� +n2��, ���� �ٸ� ���ڸ� +n3��
//
//	for (int i = 0; i < first.size(); i++)
//	{
//		if (first[i] == ' ' && second[i] == ' ') // �Ѵ� �����̸� ����
//		{
//			continue;
//		}
//
//		if (first[i] != ' ' && second[i] != ' ') // ���� �ٸ� ���ڸ� n3��
//		{
//			if (n2 * 2 > n3) // ���δٸ� �����϶� first, second�� ������ �ϳ��� �߰��ؼ� ������ �ϳ��� ���� n2 * 2�� ���δٸ� ���� ���� n3���� ũ��
//			{
//				score += n2 * 2; // ������ �ϳ��� �߰��ؼ� n2 * 2�� ȹ��
//			}
//			else // �׳� ���δٸ� ���� ������ �� ���ٸ�
//			{
//				score += n3; // n3�� ȹ��
//			}
//		}
//		else // �ϳ��� �����̸� n2��
//		{
//			score += n2;
//		}
//	}
//
//	cout << score << '\n';
//
//	return 0;
//}

