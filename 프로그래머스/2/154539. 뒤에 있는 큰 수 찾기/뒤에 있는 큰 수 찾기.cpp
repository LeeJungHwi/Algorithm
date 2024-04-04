#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    
    // numbers : 정수
    // 뒷큰수 : 자신보다 뒤에있는 숫자중 자신보다크면서 가장 가까운 수
    // answer : 각 요소의 뒷큰수, 없으면 -1
    
    // numbers 돌면서 스택에 추가하다가
    // 스택이 비어있지 않으면서 스택탑보다 큰 수를 만나면
    // 스택이 비거나 스택탑이 더 크거나같아질때까지 해당수를 뒷큰수로 저장
    
    stack<pair<int, int> > s; // (숫자, 인덱스) 쌍 저장
    
    for(int i = 0; i < numbers.size(); i++)
    {
        // 스택탑보다 큰 수를 만나면
        if(!s.empty() && s.top().first < numbers[i])
        {
            // 스택이 비거나 스택탑이 더 크거나같아질때까지 해당수를 뒷큰수로 저장
            
            while(!s.empty() && s.top().first < numbers[i])
            {
                answer[s.top().second] = numbers[i];
                s.pop();
            }
        }
        
        // 스택에 추가하다가
        s.push({numbers[i], i});
    }
    
    return answer;
}