#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    vector<string> answer;
    for(int i = 0; i < strArr.size(); i++)
    {
        bool isAD = false;
        for(int j = 0; j < strArr[i].size() - 1; j++)
        {
            if(strArr[i].substr(j, 2) == "ad")
            {
                isAD = true;
                break;
            }
        }
        if(!isAD) answer.push_back(strArr[i]);
    }
    return answer;
}