#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;
    int s1 = 0, s2 = 0;
    bool isEven = false;
    for(int i = 0; i < num_list.size(); i++)
    {
        if(!isEven) s1 += num_list[i];
        else s2 += num_list[i];
        isEven = !isEven;
    }
    return s1 > s2 ? s1 : s2;
}