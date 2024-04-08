#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    
    // 1초의 주가는 1이며 1초부터 5초까지 총 4초간 주가를 유지했습니다.
    // 2초의 주가는 2이며 2초부터 5초까지 총 3초간 주가를 유지했습니다.
    // 3초의 주가는 3이며 4초의 주가는 2로 주가가 떨어졌지만 3초에서 4초가 되기 직전까지의 1초간 주가가 유지 된것으로 봅니다. 따라서 5초까지 총 1초간 주가를 유지했습니다.
    // 4초의 주가는 2이며 4초부터 5초까지 총 1초간 주가를 유지했습니다.
    // 5초의 주가는 3이며 5초 이후로는 데이터가 없으므로 총 0초간 주가를 유지했습니다.
    // 이미 떨어진 주식가격은 더이상 고려대상이 아님 
    
    // prices : 초단위로 기록된 주식가격
    // answer : 가격이 떨어지지 않은 기간
    
    // 떨어지는 주식가격 처리
    // prices 돌면서 스택에 인덱스를 추가하다가 
    // 스택이 비거나 현재가격이 스택탑 가격보다 크거나같을때까지
    // 스택에서 꺼내서 answer에 i - 스택탑인덱스 저장
    
    stack<int> s;

    for (int i = 0; i < prices.size(); i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            int topIndex = s.top();
            s.pop();
            
            answer[topIndex] = i - topIndex;
        }
        
        // 스택에 인덱스를 추가하다가
        s.push(i);
    }

    // 절대 떨어지지않는 주식가격 처리 
    // 스택이 빌때까지
    // 스택에서 꺼내서
    // answer에 (prices.size() - 1) - topIndex 저장
    while (!s.empty())
    {
        int topIndex = s.top();
        s.pop();
        
        answer[topIndex] = (prices.size() - 1) - topIndex;
    }
    
    return answer;
}