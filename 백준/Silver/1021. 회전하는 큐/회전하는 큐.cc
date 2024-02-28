#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	int M;
	int idx = 0; // pos의 인덱스
	int ans = 0; // 2, 3연산의 최솟값
	cin >> N >> M;
	deque<int> d = {};
	for (int i = 0; i < N; i++)
	{
		d.push_back(i+1); // 1, 2, 3, ... , N
	}
	while (M--)
	{
		int pos; // 뽑아내고 싶은 수
		cin >> pos;
		for (int i = 0; i < N; i++)
		{
			if (d[i] == pos) // 덱의 요소가 pos와 일치하면
			{
				idx = i;  // 해당요소의 인덱스를 pos의 인덱스에 저장
			}
		}
		N--; // while루프 이후 덱의 크기가 감소하므로 
		while (d.front() != pos) // 덱의 앞쪽요소에 pos가 나올때까지
		{
			if (idx < d.size() - idx) // pos의 인덱스가 덱의 중간보다 왼쪽일때
			{
				d.push_back(d.front()); // 덱의 앞쪽요소를 덱의 뒤쪽에 추가
				d.pop_front(); // 덱의 앞쪽요소 제거
			}
			else // pos의 인덱스가 덱의 중간보다 오른쪽일때
			{
				d.push_front(d.back()); // 덱의 뒤쪽요소를 덱의 앞쪽에 추가
				d.pop_back(); // 덱의 뒤쪽요소 제거
			}
			ans++; // if문이 2번, else문이 3번이므로 연산 횟수 증가
		}
		d.pop_front(); // 뽑아내고자 하는 수를 뽑아내는 1번연산
	}
	cout << ans; // 2, 3 번의 연산 횟수 출력
}