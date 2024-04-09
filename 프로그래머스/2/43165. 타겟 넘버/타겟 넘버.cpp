#include <string>
#include <vector>
#include <iostream>

using namespace std;

// DFS
void DFS(int L, vector<int> &number, int tar, int &ans, int sum)
{
    if(L == number.size()) // 종료조건 : 숫자 수를 넘긴경우
    {
        // 타겟숫자가 되는지 체크해서 타겟숫자가되면 방법 수 카운팅
        // 타겟과 같으면 카운팅
        if(sum == tar)
        {
            ans++;
        }
    }
    else
    {
        // 선택한숫자는 더하고 미선택한숫자는 빼서
        DFS(L + 1, number, tar, ans, sum + number[L]); // 현재숫자 선택
        DFS(L + 1, number, tar, ans, sum - number[L]); // 현재숫자 미선택
    }
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    
    // numbers : 음이 아닌 정수, 순서를 바꾸지않고 적절히 더하거나 빼서 타겟숫자를 만들어야함
    // target : 타겟숫자
    // answer : 타겟숫자를 만드는 방법의 수
    
    // DFS 돌면서
    // 선택한숫자는 더하고 미선택한숫자는 빼서
    // 타겟숫자가 되는지 체크해서 타겟숫자가되면 방법 수 카운팅
    DFS(0, numbers, target, answer, 0);
    
    return answer;
}