#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    // arr : 숫자
    // 연속된 숫자는 하나만 남김
    
    // 1.arr 돌면서
    // 2.스택탑과 현재숫자가 같으면 현재숫자 버리고
    // 3.스택탑이 비어있거나 현재숫자와 다르면 쌓음
    // 4.스택 돌면서 answer에 저장하고 reverse
    
    stack<int> s;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(!s.empty() && s.top() == arr[i])
        {
            continue;
        }
        
        s.push(arr[i]);
    }
    
    while(!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}