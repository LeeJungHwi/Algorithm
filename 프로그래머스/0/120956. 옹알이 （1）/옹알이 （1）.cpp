#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    for(int i = 0; i < babbling.size(); i++)
    {
        string temp = "";
        for(int j = 0; j < babbling[i].size(); j++)
        {
            temp += babbling[i][j];
            if(temp == "aya" || temp == "ye" || temp == "woo" || temp == "ma")
            {
                temp = "";
                continue;
            }
        }
        cout << temp << ' ';
        if(temp.empty()) answer++;
    }
    return answer;
}