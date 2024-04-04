#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

int solution(string s)
{
    int answer = -1;
    
    // s : 대괄호, 중괄호, 소괄호로 이루어진 문자열
    // answer : s를 왼쪽으로 x(0 <= x < s 길이) 칸 만큼 회전시켰을때 s가 올바른 괄호문자열이 되게하는 x의 개수
    
    // 1.여는괄호 (, {, [ 를 만나면 스택에 push
    // 2-1.닫는괄호 ), }, ] 를 만나면 스택탑 괄호와 짝이 맞는 경우가 아니거나 스택이 비었으면 올바른괄호 아님
    // 2-2.스택탑 괄호와 짝이 맞다면 스택 pop
    // 3.모두 끝나고 스택에 괄호가 남아있으면 올바른괄호 아님
    
    // s를 회전시켜가면서 올바른괄호인지 체크
    
    int correctBracketCnt = 0; // 올바른 괄호문자열 개수
    
    for(int i = 0; i < s.size(); i++)
    {
        // s 회전
        if(i != 0)
        {
            s.push_back(s[0]);
            s.erase(0, 1);
        }
        
        // 디버깅용
        // cout << s << '\n';
        
        // 올바른괄호인지 체크
        // 1.여는괄호 (, {, [ 를 만나면 스택에 push
        // 2-1.닫는괄호 ), }, ] 를 만나면 스택탑 괄호와 짝이 맞는 경우가 아니거나 스택이 비었으면 올바른괄호 아님
        // 2-2.스택탑 괄호와 짝이 맞다면 스택 pop
        // 3.모두 끝나고 스택에 괄호가 남아있으면 올바른괄호 아님
        
        stack<char> bracket;
        bool isCorrect = true; // 올바른 괄호문자열인지 체크
        
        // 짝이맞는 괄호 맵핑
        map<char, char> matchBracket;
        matchBracket[')'] = '(';
        matchBracket['}'] = '{';
        matchBracket[']'] = '[';
        
        for(int j = 0; j < s.size(); j++)
        {
            // 1.여는괄호 (, {, [ 를 만나면 스택에 push
            if(s[j] == '(' || s[j] == '{' || s[j] == '[')
            {
                bracket.push(s[j]);
            }
            // 2-1.닫는괄호 ), }, ] 를 만나면
            else if(s[j] == ')' || s[j] == '}' || s[j] == ']')
            {
                // 스택탑 괄호와 짝이 맞는 경우가 아니거나 스택이 비었으면 올바른괄호 아님
                if(bracket.empty() || matchBracket[s[j]] != bracket.top())
                {
                    isCorrect = false;
                    
                    break;
                }
                // 2-2.스택탑 괄호와 짝이 맞다면 스택 pop
                else
                {
                    bracket.pop();
                }
            }
        }
        
        // 3.모두 끝나고 스택에 괄호가 남아있으면 올바른괄호 아님
        if(!bracket.empty())
        {
            isCorrect = false;
        }

        // 올바른괄호 문자열이면 카운팅
        if(isCorrect)
        {
            correctBracketCnt++;
        }
    }
    
    answer = correctBracketCnt;
    
    return answer;
}