#include <iostream>
using namespace std;

// 1~N 까지 M 배수합
int main()
{
	int n, m; // N, M
	int result = 0; // result
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) // 1~N 까지
	{
		if (i % m == 0)
		{
			result += i; // M 배수합
		}
	}

	cout << result << "\n";
	return 0;
}
