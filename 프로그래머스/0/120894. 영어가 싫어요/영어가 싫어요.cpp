#include <string>
#include <vector>

using namespace std;

long long solution(string numbers)
{
    long long answer = 0;
    string temp = "";
    for(int i = 0; i < numbers.size(); i++)
    {
        switch(numbers[i])
        {
            case 'z': temp += '0'; i += 3; break;
            case 'o': temp += '1'; i += 2; break;
            case 't':
                temp += numbers[i + 1] == 'w' ? '2' : '3';
                i += numbers[i + 1] == 'w' ? 2 : 4;
                break;
            case 'f':
                temp += numbers[i + 1] == 'o' ? '4' : '5';
                i += 3;
                break;
            case 's':
                temp += numbers[i + 1] == 'i' ? '6' : '7';
                i += numbers[i + 1] == 'i' ? 2 : 4;
                break;
            case 'e': temp += '8'; i += 4; break;
            case 'n': temp += '9'; i += 3; break;
        }
    }
    answer = stoll(temp);
    return answer;
}