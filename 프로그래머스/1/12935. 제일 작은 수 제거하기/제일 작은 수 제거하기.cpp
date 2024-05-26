#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    int minNum = 2147000000;
    int minIdx = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < minNum)
        {
            minNum = arr[i];
            minIdx = i;
        }
    }
    arr.erase(arr.begin() + minIdx);
    if(arr.empty()) arr.push_back(-1);
    return answer = arr;
}