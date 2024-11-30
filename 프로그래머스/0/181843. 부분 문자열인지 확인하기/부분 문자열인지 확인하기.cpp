#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target)
{
    if(my_string.size() < target.size()) return 0;
    if(my_string.size() == target.size()) return my_string == target ? 1 : 0;
    for(int i = 0; i < my_string.size() - target.size() + 1; i++) if(my_string[i] == target[0] && my_string.substr(i, target.size()) == target) return 1;
    return 0;
}