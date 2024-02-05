#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
using namespace std;

// 영화관람
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<int> students(n + 1); // 학생 저장
	vector<int> firstDisruptor(n + 1); // 각 학생의 최초 방해자 저장
	stack<int> s; // 최초 방해자 찾기용

	int height; // 학생 키

	for (int i = 1; i < n + 1; i++)
	{
		cin >> height;

		students[i] = height; // 54 52 57 50 52 53 51
	}
	
	// 마지막 학생부터 돌면서
	// 스택이 비거나 스택 top 학생 >= i번째 학생 일때 종료
	// 스택 top 학생의 최초 방해자는 i번째 학생의 키로 저장 후 pop
	// i번째 학생 키 스택에 저장

	// 51 push
	// 51 < 53 -> while 진입 -> 51의 최초방해자는 53의 인덱스 -> 6
	// 51 pop 후 53 push
	// 53 > 52
	// 52 push
	// 52 > 50
	// 50 push
	// 50 < 57 -> while 진입 -> 50의 최초 방해자는 57의 인덱스 -> 3
	// 50 pop
	// 52 < 57 -> while 진입 -> 52의 최초 방해자는 57의 인덱스 -> 3
	// 52 pop
	// 53 < 57 -> while 진입 -> 53의 최초 방해자는 57의 인덱스 -> 3
	// 53 pop 후 57 push
	// 57 > 52
	// 52 push
	// 52 < 54 -> while 진입 -> 52의 최초 방해자는 54의 인덱스 -> 1
	// 52 pop 후 54 push
	// 0으로 초기화 되었으므로 최초 방해자가 없거나 첫번째 학생은 0

	for (int i = n; i > 0; i--)
	{
		while (!s.empty() && students[s.top()] < students[i])
		{
			firstDisruptor[s.top()] = i;
			s.pop();
		}

		s.push(i);
	}

	for (int i = 1; i < n + 1; i++)
	{
		cout << firstDisruptor[i] << ' ';
	}

	return 0;
}