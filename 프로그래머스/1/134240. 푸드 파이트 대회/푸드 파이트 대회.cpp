#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";
    for(int i = 1; i < food.size(); i++)
    {
        // 1(물) 3 0 1
        food[i] /= 2;
        for(int j = 0; j < food[i]; j++)
        {
            // 1 1 1 3
            answer += i + '0';
        }
    }
    string rans = answer;
    reverse(rans.begin(), rans.end());
    rans = '0' + rans;
    answer += rans;
    //cout << answer << '\n';
    
    return answer;
}