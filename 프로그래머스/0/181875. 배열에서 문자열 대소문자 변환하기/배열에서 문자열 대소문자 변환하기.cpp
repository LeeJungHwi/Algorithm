#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    bool isEven = true;
    for(int i = 0; i < strArr.size(); i++)
    {
        if(isEven)
        {
            for(int j = 0; j < strArr[i].size(); j++)
            {
                if(isupper(strArr[i][j])) strArr[i][j] = tolower(strArr[i][j]);
            }
        }
        else
        {
            for(int j = 0; j < strArr[i].size(); j++)
            {
                if(islower(strArr[i][j])) strArr[i][j] = toupper(strArr[i][j]);
            }
        }
        
        isEven = !isEven;
    }
    
    return strArr;
}