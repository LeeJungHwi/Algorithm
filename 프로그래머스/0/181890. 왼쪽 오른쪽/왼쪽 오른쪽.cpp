#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list)
{
    vector<string> answer;
    bool isFirst = false;
    for(int i = 0; i < str_list.size(); i++)
    {
        if(!isFirst)
        {
            if(str_list[i] == "l") return answer;
            if(str_list[i] == "r")
            {
                isFirst = true;
                answer.clear();
                continue;
            }
        }
        string temp(str_list[i]);
        answer.push_back(temp);
    }
    return isFirst ? answer : vector<string>();
}