#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

// K진수 출력
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	stack<int> base;

	// 진법변환
	while (n / k != 0)
	{
		base.push(n % k);
		n /= k;
	}

	base.push(n % k);

	// 진수 출력
	while (!base.empty())
	{
		// 16 진수
		if (k == 16)
		{
			switch (base.top())
			{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
					cout << base.top();
					break;
				case 10:
					cout << 'A';
					break;
				case 11:
					cout << 'B';
					break;
				case 12:
					cout << 'C';
					break;
				case 13:
					cout << 'D';
					break;
				case 14:
					cout << 'E';
					break;
				case 15:
					cout << 'F';
					break;
			}

			base.pop();
			continue;
		}

		// 2,5,8 진수
		cout << base.top();
		base.pop();
	}

	return 0;
}
// 핵심
// 진법변환 식