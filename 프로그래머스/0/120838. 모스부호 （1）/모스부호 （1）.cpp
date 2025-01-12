#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string letter)
{
    string answer = "";
    map<string, char> m =
    {
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'},
        {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'},
        {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'},
        {"...", 's'}, {"-", 't'}, {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'},
        {"-.--", 'y'}, {"--..", 'z'}, 
    };
    letter += ' ';
    string temp = "";
    for(int i = 0; i < letter.size(); i++)
    {
        if(letter[i] == ' ')
        {
            answer += m[temp];
            temp.clear();
            continue;
        }
        temp += letter[i];
    }
    return answer;
}