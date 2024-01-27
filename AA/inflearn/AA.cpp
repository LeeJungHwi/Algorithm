#include <iostream>
using namespace std;

// 1~N 까지 M 배수합
int main()
{
	int n, m; // N, M
	int result = 0; // result
	cin >> n >> m;

	for (int i = m; i < n + 1; i += m) // m의 배수를 더함
	{
		result += i;
	}

	cout << result << "\n";
	return 0;
}
