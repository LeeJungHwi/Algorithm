#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    int answer = 0, idx = -1;
    string temp = "";
    char op = 'a';
    bool isFirst = false;
    my_string += '+';
    for(int i = 0; i < my_string.size(); i++)
    {
        if(my_string[i] == ' ') continue;
        if(my_string[i] == '+' || my_string[i] == '-')
        {
            if(!isFirst)
            {
                answer = stoi(temp);
                isFirst = true;
            }
            else answer = op == '+' ? answer + stoi(temp) : answer - stoi(temp);
            
            op = my_string[i];
            temp = "";
            
            continue;
        }
        
        temp += my_string[i];
    }
    
    return answer;
}