#include <iostream>

using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;
    string temp = "";
    for(int i = 0; i < n; i++) temp += '*';
    for(int i = 0; i < m; i++) cout << temp << '\n';
    return 0;
}