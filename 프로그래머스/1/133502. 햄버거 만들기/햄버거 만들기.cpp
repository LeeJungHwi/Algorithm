#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    
    // ingredient : 상수에게 전해지는 재료의 정보, 1(빵) 2(야채) 3(고기)
    // 1(빵) 2(야채) 3(고기) 1(빵) 순서로 스택에 쌓이면 answer++
    
    stack<int> s;
    
    for (int i = 0; i < ingredient.size(); i++)
    {
        if(s.size() >= 3 && s.top() == 3 && ingredient[i] == 1)
        {
            // 임시스택에 고기 저장
            stack<int> temp;
            temp.push(s.top());
            s.pop();
            
            // 야채가 아니면 임시스택 요소와 현재재료를 s에 저장 후 conitnue
            if(s.top() != 2)
            {
                while(!temp.empty())
                {
                    s.push(temp.top());
                    temp.pop();
                }
                
                s.push(ingredient[i]);
                
                continue;
            }
            
            // 야채면 임시스택에 야채 저장
            temp.push(s.top());
            s.pop();
            
            // 빵이 아니면 임시스택 요소와 현재재료를 s에 저장 후 continue
            if(s.top() != 1)
            {
                while(!temp.empty())
                {
                    s.push(temp.top());
                    temp.pop();
                }
                
                s.push(ingredient[i]);
                
                continue;
            }
            
            // 여기까지 왔으면 햄버거가 완성된거임
            s.pop();
            answer++;
            
            continue;
        }
        
        // 3 1 이 아니면 그냥 스택에 저장함
        s.push(ingredient[i]);
    }
    
    return answer;
}