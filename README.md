⭐️ PS (with. cpp)

<!--
[![Solved.ac
프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=wnd4114294225)](https://solved.ac/wnd4114294225)

```cpp
#include "mylib.h"

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
bool IsEscapePS(int curBaekjoonSolve, string curBaekjoonTier, int curProgrammersSolve, string curCodeforcesTier)
{
    if(curBaekjoonSolve < 1000) return false;
    if(curBaekjoonTier != "diamond5") return false;
    if(curProgrammersSolve < 500) return false;
    if(curCodeforcesTier != "blue") return false;

    return true;
}

// PS 탈출
int main()
{
    Baekjoon myBaekjoon = Baekjoon("wnd4114294225", 325, "platinum5");
    Programmers myProgrammers = Programmers("wnd4114294225", 116);
    Codeforces myCodeforces = Codeforces("wnd4114294225", "Unrated");

    while(!IsEscapePS(myBaekjoon.solveCnt, myBaekjoon.tier, myProgrammers.solveCnt, myCodeforces.tier))
        elp("PS 탈출 ㄴㄴ");

    elp("PS 탈출 ㅇㅇ");

    return home;
}
```
-->
