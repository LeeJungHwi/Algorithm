#include <iostream>
using namespace std;

// 진약수 합
int main()
{
	int n; // N
	int result = 1; // result
	
	cin >> n;

	cout << 1; // 1

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) // + 2 + 4 ...
		{
			cout << " + " << i;
			result += i;
		}
	}

	cout << " = " << result << "\n"; // = result
	return 0;
}

// 핵심
// 진약수 -> 자기자신을 제외한 약수
// " + "를 앞에 쓰기