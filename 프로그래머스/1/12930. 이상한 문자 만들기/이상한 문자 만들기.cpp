#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    
    s += ' ';
    bool isEven = true;
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            for(int j = 0; j < temp.size(); j++)
            {
                answer += isEven ? toupper(temp[j]) : tolower(temp[j]);
                isEven = !isEven;
            }
            
            answer += ' ';
            isEven = true;
            temp.clear();
            continue;
        }
        
        temp += s[i];
    }
    answer.pop_back();
    
    return answer;
}