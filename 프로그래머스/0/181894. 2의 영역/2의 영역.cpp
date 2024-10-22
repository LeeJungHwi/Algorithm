#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int first = -1, last = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(first == -1 && arr[i] == 2)
        {
            first = i;
            last = i;
            continue;
        }
        
        if(arr[i] == 2) last = i;
    }
    
    if(first == -1) return {-1};
    for(int i = first; i < last + 1; i++) answer.push_back(arr[i]);
    
    return answer;
}