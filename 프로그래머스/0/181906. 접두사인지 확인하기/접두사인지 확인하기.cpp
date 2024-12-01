#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix)
{
    for(int i = 0; i < my_string.size(); i++) if(my_string.substr(0, my_string.size() - i) == is_prefix) return 1;
    return 0;
}