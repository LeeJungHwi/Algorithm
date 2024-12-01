#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int l, int r)
{
    vector<int> answer;
    for(int i = l; i < r + 1; i++)
    {
        string temp = to_string(i);
        bool is = true;
        
        for(int j = 0; j < temp.size(); j++)
        {
            if(temp[j] != '0' && temp[j] != '5')
            {
                is = false;
                break;
            }
        }
        
        if(is) answer.push_back(stoi(temp));
    }
    
    if(answer.empty()) answer.push_back(-1);
    return answer;
}