#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n)
{
    int answer = 0;
    int m = 2147000000;
    for(int i = 0; i < array.size(); i++)
    {
        if(m > abs(n - array[i]))
        {
            m = abs(n - array[i]);
            answer = array[i];
        }
        else if(m == abs(n - array[i]))
        {
            if(answer > array[i])
            {
                answer = array[i];
            }
        }
    }
    return answer;
}