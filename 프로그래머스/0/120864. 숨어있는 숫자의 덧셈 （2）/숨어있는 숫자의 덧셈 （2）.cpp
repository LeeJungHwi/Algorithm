#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    int answer = 0;
    string temp = "";
    my_string += 'a';
    for(int i = 0; i < my_string.size(); i++)
    {
        if(!temp.empty() && isalpha(my_string[i]))
        {
            answer += stoi(temp);
            temp = "";
            continue;
        }
        
        if(isdigit(my_string[i])) temp += my_string[i];
    }
    return answer == 0 ? 0 : answer;
}