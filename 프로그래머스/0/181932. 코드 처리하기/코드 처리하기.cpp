#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
    string answer = "";
    bool mode = 0;
    for(int i = 0; i < code.size(); i++)
    {
        if(code[i] == '1')
        {
            mode = !mode;
            continue;
        }
        
        if(i % 2 == mode) answer += code[i];
    }
    
    return answer.empty() ? "EMPTY" : answer;
}