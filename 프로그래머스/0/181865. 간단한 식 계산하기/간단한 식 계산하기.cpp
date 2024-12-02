#include <string>
#include <vector>

using namespace std;

int solution(string binomial)
{
    int a = 0, b = 0, idx = -1;
    char op = '+';
    string temp = "";
    for(int i = 0; i < binomial.size(); i++)
    {
        if(binomial[i] == ' ')
        {
            a = stoi(temp);
            op = binomial[++i];
            b = stoi(binomial.substr(i + 2, binomial.size() - i + 2));
            break;
        }
        
        temp += binomial[i];
    }
    
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
}