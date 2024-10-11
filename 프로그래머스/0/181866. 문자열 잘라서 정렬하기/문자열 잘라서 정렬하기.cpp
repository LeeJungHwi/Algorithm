#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString)
{
    vector<string> answer;
    if(myString[myString.size() - 1] != 'x') myString += 'x';
    string temp = "";
    for(int i = 0; i < myString.size(); i++)
    {
        if(myString[i] == 'x')
        {
            if(!temp.empty())
            {
                answer.push_back(temp);
                temp.clear();
            }
            continue;
        }
        
        temp += myString[i];
    }
    sort(answer.begin(), answer.end());
    return answer;
}