#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter)
{
    for(int i = 0; i < my_string.size(); i++)
    {
        if(my_string[i] == letter[0])
        {
            my_string.erase(i, 1);
            i--;
        }
    }
    return my_string;
}