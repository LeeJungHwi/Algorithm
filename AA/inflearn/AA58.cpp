#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 이진트리 순회
// child(1) : 왼쪽자식 재귀호출 오른쪽자식 재귀호출
// 7번까지만 생성
void Traversal(int rootNode)
{
	if (rootNode > 7)
	{
		return;
	}
	else
	{
		//cout << rootNode << ' '; // 전위순회
		Traversal(rootNode * 2);
		//cout << rootNode << ' '; // 중위순회
		Traversal(rootNode * 2 + 1);
		//cout << rootNode << ' '; // 후위순회
	}
}

// 이진트리 깊이우선탐색
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 이진트리 왼쪽 자식노드 = 부모노드 * 2
	// 이진트리 오른쪽 자식노드 = 부모노드 * 2 + 1
	// 전위순회 : 부모 왼쪽 오른쪽
	// 중위순회 : 왼쪽 부모 오른쪽
	// 후위순회 : 왼쪽 오른쪽 부모

	// 이진트리 생성
	Traversal(1);

	return 0;
}