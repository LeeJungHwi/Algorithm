#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr)
{
    vector<string> answer;
    string temp = "";
    myStr += 'a';
    for(int i = 0; i < myStr.size(); i++)
    {
        if(myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c')
        {
            if(temp.empty()) continue;
            answer.push_back(temp);
            temp = "";
            continue;
        }
        
        temp += myStr[i];
    }
    
    if(answer.empty()) answer.push_back("EMPTY");
    return answer;
}