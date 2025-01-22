#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool isFirst = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(isspace(s[i]))
        {
            isFirst = false;
            answer += ' ';
            continue;
        }
        
        if(!isFirst)
        {
            isFirst = true;
            answer += islower(s[i]) ? toupper(s[i]) : s[i];
            continue;
        }
        
        answer += isupper(s[i]) ? tolower(s[i]) : s[i];
    }
    return answer;
}