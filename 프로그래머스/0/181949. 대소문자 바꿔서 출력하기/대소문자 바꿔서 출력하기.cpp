#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); i++) cout << (char)(islower(str[i]) ? toupper(str[i]) : tolower(str[i]));
    
    return 0;
}