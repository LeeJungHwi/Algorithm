#include <string>
#include <vector>

using namespace std;

int solution(int num, int k)
{
    string temp = to_string(num);
    for(int i = 0; i < temp.size(); i++) if(temp[i] == k + '0') return ++i;
    return -1;
}