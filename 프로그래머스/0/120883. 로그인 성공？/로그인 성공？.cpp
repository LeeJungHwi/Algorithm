#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    map<string, string> idMap;
    
    for(int i = 0; i < db.size(); i++)
    {
        idMap[db[i][0]] = db[i][1];
    }
    
    if (idMap.find(id_pw[0]) == idMap.end()) return "fail";
    if (idMap[id_pw[0]] != id_pw[1]) return "wrong pw";
    return "login";
}