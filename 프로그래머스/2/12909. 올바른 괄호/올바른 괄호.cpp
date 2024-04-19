#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    // s : 괄호문자열
    // 올바른지 체크
    
    // (면 cnt++
    // )면 cnt--
    // 중간에 cnt < 0 이면 X
    // 다 끝나고 cnt > 0 이면 X
    
    int cnt = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') cnt++;
        else cnt--;
        
        if(cnt < 0) return answer = false;
    }
    
    if(cnt > 0) return answer = false;

    return answer;
}