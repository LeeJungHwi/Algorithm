#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order)
{
    int answer = 0;
    
    // order : 택배기사님이 원하는 상자 순서
    // answer : 택배상자를 몇개 실을 수 있는지
    
    // order 돌면서 스택에 추가하다가
    // 보조컨테이너가 비거나 보조컨테이너 탑이 원하는숫자가 아니면 종료
    // 원하는 숫자면 pop, answer++
    
    stack<int> subContainer; // 보조 컨테이너
    
    // order 돌면서
    for (int i = 1; i < order.size() + 1; i++)
    {
        // 스택에 추가하다가
        subContainer.push(i);
    
        // 보조컨테이너가 비거나 보조컨테이너 탑이 원하는숫자가 아니면 종료
        while (true)
        {
            if(subContainer.empty() || subContainer.top() != order[answer])
            {
                break;
            }
            
            // 원하는 숫자면 pop, answer++
            subContainer.pop();
            answer++;
        }
    }
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <stack>
// #include <iostream>

// using namespace std;

// int solution(vector<int> order)
// {
//     int answer = 0;
    
//     // order : 택배기사님이 원하는 상자 순서
//     // answer : 택배상자를 몇개 실을 수 있는지
    
//     // order 돌면서 스택이 비었으면 현재숫자가 원하는숫자가 아니면 스택에 쌓고 원하는 숫자면 answer++
//     // 스택에 요소가 있다면 스택탑이 원하는 숫자면 pop하고 answer++
//     // 스택탑이 원하는 숫자가 아니면 현재숫자가 원하는 숫자면 answer++
//     // 둘다 원하는 숫자가 아니면 스택에 쌓음
//     // 스택이 빌때까지 스택탑이 원하는숫자가 아닐때까지 answer++
    
//     stack<int> subContainer; // 보조 컨테이너
    
//     // order 돌면서
//     for(int i = 1; i < order.size() + 1; i++)
//     {
//         // 스택이 비어있다면
//         if(subContainer.empty())
//         {
//             // 현재숫자가 원하는 순서가 아니면 스택에 쌓음
//             if(i != order[answer])
//             {
//                 subContainer.push(i);
                
//                 continue;
//             }
            
//             // 현재숫자가 원하는 숫자면 answer++
//             answer++;
            
//             continue;
//         }
        
//         // 스택에 요소가 있다면
//         // 스택탑이 원하는 숫자면 pop하고 answer++
//         // 스택탑이 원하는 숫자가 아니면 현재숫자가 원하는 숫자면 answer++
//         // 둘다 원하는 숫자가 아니면 스택에 쌓음
        
//         if(subContainer.top() == order[answer])
//         {
//             subContainer.pop();
//             answer++;
//             continue;
//         }
        
//         if(i == order[answer])
//         {
//             answer++;
//             continue;
//         }
        
//         subContainer.push(i);
//     }
    
//     // 스택이 빌때까지
//     while(!subContainer.empty())
//     {
//         // 스택탑이 원하는숫자가 아닐때까지 answer++
//         if(subContainer.top() != order[answer])
//         {
//             break;
//         }
        
//         answer++;
//         subContainer.pop();
//     }
    
//     return answer;
// }