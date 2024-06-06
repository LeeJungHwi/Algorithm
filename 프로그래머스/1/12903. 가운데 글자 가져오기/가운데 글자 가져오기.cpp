#include <string>
#include <vector>
using namespace std;

string home;

string solution(string s) { return home = !(s.size() % 2) ? s.substr(s.size() / 2 - 1, 2) : s.substr(s.size() / 2, 1); }