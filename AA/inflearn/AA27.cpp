#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �Ҽ����� üũ�ϴ� �Լ�
bool CheckPrime(int num, int n)
{
	if (num <= 3)
	{
		return true;
	}

	for (int i = 2; i < num; i++) // 1�� �ڽŻ��� �������� ���� �������� �Ҽ� �ƴ�
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

// �Ҽ��� �� ���� ���� ī����
// 5
// 5! = 3 1 1
//     (2 3 5)
// 6
// 6! = 2 3 2 2 5 2 3 = 4 2 1
void ExpressionFactorial(int n, bool isPrime, vector<int> &primeVector, int share, vector<int> &cntPrimeVector)
{
	for (int i = 2; i < n + 1; i++) // 2����n���� ������Ű�鼭
	{
		share = i; // ���⼭ �ʱ�ȭ

		if (!CheckPrime(i, n)) // �Ҽ��� �ƴѼ��� ������
		{
			while (true) // �Ҽ��� ���� ���� �Ҽ��϶����� �ݺ�
			{
				for (int j = 0; j < primeVector.size(); j++) // �Ҽ� ���Ϳ��� �������ִ� �Ҽ� ã��
				{
					if (share % primeVector[j] == 0) // j��° �Ҽ��� ����������
					{
						share = share / primeVector[j]; // j�� ���� �� ����
						cntPrimeVector[j]++; // j�� �Ҽ��̹Ƿ� ī��Ʈ
						break;
					}
				}

				if (CheckPrime(share, n)) // ���� �Ҽ��� ����
				{
					break;
				}
			}

			// share�� while�� ����Ǿ�� �Ҽ��̹Ƿ� while �ۿ��� ī���� �� share �ʱ�ȭ
			for (int j = 0; j < primeVector.size(); j++)
			{
				if (share == primeVector[j])
				{
					cntPrimeVector[j]++; // �Ҽ� ���Ϳ��� �������� ã�� ī����
				}
			}

			continue;
		}

		// �Ҽ��� ���
		for (int j = 0; j < primeVector.size(); j++)
		{
			if (i == primeVector[j])
			{
				cntPrimeVector[j]++; // �Ҽ� ���Ϳ��� �������� ã�� ī����
			}
		}
	}

	cout << n << "! = ";
	for (int i = 0; i < cntPrimeVector.size(); i++)
	{
		cout << cntPrimeVector[i] << ' ';
	}
}

// N! ǥ����
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	// 2����n���� �����ϴ� �Ҽ� ����
	vector<int> primeVec;
	bool isPrime = true;
	for (int i = 2; i < n + 1; i++)
	{
		isPrime = CheckPrime(i, n);
		if (isPrime)
		{
			primeVec.push_back(i); // (2 3 5)
		}
	}
	isPrime = true;

	int share = 0; // ��

	vector<int> cntPrimeVec(primeVec.size(), 0); // �Ҽ� ���� ī��Ʈ

	ExpressionFactorial(n, isPrime, primeVec, share, cntPrimeVec);

	return 0;
}

// �ٽ�
// �� �ʱ�ȭ ��ġ