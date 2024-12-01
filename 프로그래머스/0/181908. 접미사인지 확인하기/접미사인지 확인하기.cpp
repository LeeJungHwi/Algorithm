#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix)
{
    for(int i = 0; i < my_string.size(); i++) if(my_string.substr(i, my_string.size() - i) == is_suffix) return 1;
    return 0;
}