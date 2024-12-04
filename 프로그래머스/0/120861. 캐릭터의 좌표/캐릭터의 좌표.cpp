#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    vector<int> answer;
    map<string, pair<int, int> > dMap;
    vector<pair<int, int> > dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    dMap["left"] = dir[2];
    dMap["right"] = dir[3];
    dMap["up"] = dir[0];
    dMap["down"] = dir[1];
    pair<int, int> cur = {0, 0};
    for(int i = 0; i < keyinput.size(); i++)
    {
        int ci = cur.first + dMap[keyinput[i]].first;
        int cj = cur.second + dMap[keyinput[i]].second;
        cout << ci << ' ' << cj << '\n';
        if(ci < (board[1] - 1) / 2 * -1 || cj < (board[0] - 1) / 2 * -1 || ci > (board[1] - 1) / 2 || cj > (board[0] - 1) / 2) continue;
        cur = {ci, cj};
    }
    answer.push_back(cur.second);
    answer.push_back(-1 * cur.first);
    return answer;
}