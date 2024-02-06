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
	
	// 마지막 학생부터 돌면서 나 자신이 누구의 최초 방해자인지 체크하기
	// 스택이 비거나 내가 더 작으면 그냥 스택에 저장
	// 스택이 비어있지 않으면서 내가 더 크면 스택 top의 최초 방해자는 나가 되고 최초방해자를 찾은 스택 top은 pop하고 나를 스택에 저장

	// 스택이 비어있음
	// 51 : 스택이 비어있으므로 51 스택에 저장
	// 53 : 스택이 비어있지 않으면서 51 보다 큼 -> 51의 최초 방해자는 53 -> 51의 최초 방해자를 찾았으므로 51 pop -> 53 스택에 저장
	// 52 : 53 보다 작으므로 52 스택에 저장
	// 50 : 52 보다 작으므로 50 스택에 저장
	// 57 : 스택이 비어있지 않으면서 50 보다 큼 -> 50의 최초 방해자는 57 -> 50의 최초 방해자를 찾았으므로 50 pop
	// -> 스택이 비어있지 않으면서 52 보다 큼 -> 52의 최초 방해자는 57 -> 52의 최초 방해자를 찾았으므로 52 pop
	// -> 스택이 비어있지 않으면서 53 보다 큼 -> 53의 최초 방해자는 57 -> 53의 최초 방해자를 찾았으므로 53 pop -> 57 스택에 저장
	// 52 : 57 보다 작으므로 52 스택에 저장
	// 54 : 스택이 비어있지 않으면서 52 보다 큼 -> 52의 최초 방해자는 54 -> 52의 최초 방해자를 찾았으므로 52 pop -> 54 스택에 저장
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