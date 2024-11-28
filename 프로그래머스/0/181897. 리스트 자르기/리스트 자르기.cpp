#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list)
{
    vector<int> answer;
    int s = slicer[0], e = slicer[1] + 1;
    switch(n)
    {
        case 1: s = 0; break;
        case 2: e = num_list.size(); break;
        default: break;
    }
    for(int i = s; i < e; n < 4 ? i++ : i += slicer[2]) answer.push_back(num_list[i]);
    return answer;
}