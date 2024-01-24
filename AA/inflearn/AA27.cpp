#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 소수인지 체크하는 함수
bool CheckPrime(int num, int n)
{
	if (num <= 3)
	{
		return true;
	}

	for (int i = 2; i < num; i++) // 1과 자신빼고 나눴을때 나눠 떨어지면 소수 아님
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

// 소수가 된 수의 개수 카운팅
// 5
// 5! = 3 1 1
//     (2 3 5)
// 6
// 6! = 2 3 2 2 5 2 3 = 4 2 1
void ExpressionFactorial(int n, bool isPrime, vector<int> &primeVector, int share, vector<int> &cntPrimeVector)
{
	for (int i = 2; i < n + 1; i++) // 2부터n까지 증가시키면서
	{
		share = i; // 여기서 초기화

		if (!CheckPrime(i, n)) // 소수가 아닌수를 만나면
		{
			while (true) // 소수로 나눈 몫이 소수일때까지 반복
			{
				for (int j = 0; j < primeVector.size(); j++) // 소수 벡터에서 나눌수있는 소수 찾기
				{
					if (share % primeVector[j] == 0) // j번째 소수로 나눌수있음
					{
						share = share / primeVector[j]; // j로 나눈 몫 저장
						cntPrimeVector[j]++; // j는 소수이므로 카운트
						break;
					}
				}

				if (CheckPrime(share, n)) // 몫이 소수면 종료
				{
					break;
				}
			}

			// share는 while이 종료되어야 소수이므로 while 밖에서 카운팅 후 share 초기화
			for (int j = 0; j < primeVector.size(); j++)
			{
				if (share == primeVector[j])
				{
					cntPrimeVector[j]++; // 소수 벡터에서 같은값을 찾아 카운팅
				}
			}

			continue;
		}

		// 소수인 경우
		for (int j = 0; j < primeVector.size(); j++)
		{
			if (i == primeVector[j])
			{
				cntPrimeVector[j]++; // 소수 벡터에서 같은값을 찾아 카운팅
			}
		}
	}

	cout << n << "! = ";
	for (int i = 0; i < cntPrimeVector.size(); i++)
	{
		cout << cntPrimeVector[i] << ' ';
	}
}

// N! 표현법
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	// 2부터n까지 존재하는 소수 저장
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

	int share = 0; // 몫

	vector<int> cntPrimeVec(primeVec.size(), 0); // 소수 개수 카운트

	ExpressionFactorial(n, isPrime, primeVec, share, cntPrimeVec);

	return 0;
}

// 핵심
// 몫 초기화 위치