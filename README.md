[![Solved.ac
프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=wnd4114294225)](https://solved.ac/wnd4114294225)

<br>

```cpp
#include <bits/stdc++.h>
using namespace std;

#define home 0
#define cond(c, t, f) ((c) ? (t) : (f))
#define elprint(a) cout << a << '\n'

// 백준
struct Baekjoon
{
    string id;
    int solveCnt;
    string tier;

    Baekjoon() {}
    Baekjoon(string i, int s, string t) : id(i), solveCnt(s), tier(t) {}
};

// 프로그래머스
struct Programmers
{
    string id;
    int solveCnt;

    Programmers() {}
    Programmers(string i, int s) : id(i), solveCnt(s) {}
};

// 코드포스
struct Codeforces
{
    string id;
    string tier;

    Codeforces() {}
    Codeforces(string i, string t) : id(i), tier(t) {}
};

// PS 목표
bool IsCondition(int curBaekjoonSolve, string curBaekjoonTier, int curProgrammersSolve, string curCodeforcesTier)
{
    if(curBaekjoonSolve < 1000) return false;
    if(curBaekjoonTier != "diamond5") return false;
    if(curProgrammersSolve < 500) return false;
    if(curCodeforcesTier != "blue") return false;

    return true;
}

bool IsEscapePS(int curBaekjoonSolve, string curBaekjoonTier, int curProgrammersSolve, string curCodeforcesTier)
{ return cond(IsCondition(curBaekjoonSolve, curBaekjoonTier, curProgrammersSolve, curCodeforcesTier), true, false); }

// PS 탈출
int main()
{
    Baekjoon myBaekjoon = Baekjoon("wnd4114294225", 325, "platinum5");
    Programmers myProgrammers = Programmers("wnd4114294225", 116);
    Codeforces myCodeforces = Codeforces("wnd4114294225", "Unrated");

    while(!IsEscapePS(myBaekjoon.solveCnt, myBaekjoon.tier, myProgrammers.solveCnt, myCodeforces.tier)) elprint("PS 탈출 ㄴㄴ");

    elprint("PS 탈출 ㅇㅇ");

    return home;
}
```
