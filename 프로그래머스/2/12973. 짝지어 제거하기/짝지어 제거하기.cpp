#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;

    // 스택에 쌓으면서 스택탑과 같은 문자면 스택 pop
    // 스택이 비었으면 1 아니면 0
    
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(!st.empty() && st.top() == s[i])
        {
            st.pop();
            continue;
        }
        
        st.push(s[i]);
    }

    return answer = st.empty() ? 1 : 0;
}