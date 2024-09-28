#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<string> st;
    s += ' ';
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            st.push(temp);
            temp.clear();
            continue;
        }
        temp += s[i]; 
    }
    
    while(!st.empty())
    {
        if(st.top()[0] == 'Z')
        {
            st.pop();
            st.pop();
            continue;
        }
        answer += stoi(st.top());
        st.pop();
    }
    
    return answer;
}