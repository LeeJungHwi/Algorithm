#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr)
{
    vector<vector<int>> answer;
    if(arr.size() > arr[0].size())
    {
        int e = arr.size() - arr[0].size();
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = 0; j < e; j++)
            {
                arr[i].push_back(0);
            } 
        }
        return arr;
    }
    else if(arr.size() < arr[0].size())
    {
        int e = arr[0].size() - arr.size();
        for(int i = 0; i < e; i++)
        {
            vector<int> temp(arr[0].size());
            arr.push_back(temp);
        }
        return arr;
    }
    else return arr;
}