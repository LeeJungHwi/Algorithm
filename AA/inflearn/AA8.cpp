#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

// 올바른 괄호
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");
	
	string input; // 입력 괄호
	cin >> input;

	stack<char> p; // 괄호 스택

	string result; // 결과

	int pushCnt = 0; // push 횟수

	// 1. 닫는괄호일때까지 push
	// 2. 닫는괄호일때 pop 두번
	// 3. 입력과 스택이 비었으면 YES
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != ')') // 닫는괄호가 아니면
		{
			p.push(input[i]);
			pushCnt++;
		}
		else // 닫는괄호
		{
			if (!p.empty())
			{
				p.push(input[i]);
				pushCnt++;
				p.pop();
				p.pop();
			}
		}
	}

	if (p.empty() && pushCnt == input.size()) // 스택이 비어있고 입력괄호를 모두 읽었으면
	{
		cout << "YES\n";
		return 0;
	}
	
	cout << "NO\n";
	return 0;
}

// 핵심
// 입력스트링과 스택이 모두 비어야 올바른 괄호