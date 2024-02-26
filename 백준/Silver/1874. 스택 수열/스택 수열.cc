#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

// 스택수열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 스택을 이용해 오름차순 수열을 만들어야함
	// push는 + pop은 -
	// + + + + numStack(1 2 3 4) curNum 5
	// - - numStack(1 2) curNum 5
	// + + numStack(1 2 5 6) curNum 7
	// - numStack(1 2 5) curNum 7
	// + + numStack(1 2 5 7 8) curNum 9
	// - - - - -

	int n; // N 8
	cin >> n;

	int num; // 숫자
	vector<int> inputNums; // 입력숫자 저장
	vector<int> stackPop; // 스택에서 꺼내 수열을 만든 숫자 저장
	stack<int> numStack; // 숫자스택
	queue<char> opStack; // 연산자큐

	// 입력숫자 저장
	// 4 3 6 8 7 5 2 1
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		inputNums.push_back(num);
	}

	int curIndex = 0; // 헌재 체크할 입력숫자 인덱스 
	int curNum = 1; // 현재 push 할 숫자

	while (true)
	{
		// 스택 탑이 현재 뽑아내야할 입력숫자 일때까지 push
		while (numStack.empty() || numStack.top() != inputNums[curIndex])
		{
			// push
			numStack.push(curNum);
			opStack.push('+');
			curNum++;

			// n까지 push했으면 남은 숫자 모두 pop하면서 스택수열 저장
			if (curNum == n + 1)
			{
				while (!numStack.empty())
				{
					stackPop.push_back(numStack.top());
					numStack.pop();
					opStack.push('-');
				}

				break;
			}
		}

		// 다음 입력숫자 체크
		curIndex++;

		// 스택 탑이 num이면 pop하면서 스택수열 저장
		if (!numStack.empty())
		{
			stackPop.push_back(numStack.top());
			numStack.pop();
			opStack.push('-');
		}

		// n까지 push했으면 남은 숫자 모두 pop하면서 스택수열 저장
		if (curNum == n + 1)
		{
			while (!numStack.empty())
			{
				stackPop.push_back(numStack.top());
				numStack.pop();
				opStack.push('-');
			}

			break;
		}
	}

	// 저장된 입력숫자와 스택에서 pop한 숫자가 하나라도 다르면 NO 출력
	for (int i = 0; i < inputNums.size(); i++)
	{
		if (inputNums[i] != stackPop[i])
		{
			cout << "NO" << '\n';

			return 0;
		}
	}

	// 모두 같으면 연산자큐 출력
	while (!opStack.empty())
	{
		cout << opStack.front() << '\n';
		opStack.pop();
	}

	return 0;
}