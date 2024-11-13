#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int s = 0, m = 1;
    for(int i = 0; i < num_list.size(); i++)
    {
        s += num_list[i];
        m *= num_list[i];
    }
    
    return m < s * s ? 1 : 0;
}