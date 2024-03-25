#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 역원소 정렬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	long long n; // N 10
	cin >> n;

	string num; // 숫자 50000000
	vector<long long> numVec; // 숫자들 저장

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		// 뒤집고 숫자로 바꿔서 저장
		reverse(num.begin(), num.end());

		numVec.push_back(stoll(num));
	}

	// 정렬 후 출력
	sort(numVec.begin(), numVec.end());

	for (int i = 0; i < numVec.size(); i++)
	{
		cout << numVec[i] << '\n';
	}

	return 0;
}