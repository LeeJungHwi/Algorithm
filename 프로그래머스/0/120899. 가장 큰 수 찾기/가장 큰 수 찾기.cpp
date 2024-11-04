#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array)
{
    vector<int> answer;
    int idx = -1;
    int maxV = 0;
    for(int i = 0; i < array.size(); i++)
    {
        if(array[i] > maxV)
        {
            idx = i;
            maxV = array[i];
        }
    }
    answer.push_back(maxV);
    answer.push_back(idx);
    return answer;
}