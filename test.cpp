#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <locale>
using namespace std;

string ws2s(const wstring &ws)
{
    string curLocale = setlocale(LC_ALL, NULL); // curLocale = "C";

    setlocale(LC_ALL, "chs");

    const wchar_t *_Source = ws.c_str();
    size_t _Dsize = 2 * ws.size() + 1;
    char *_Dest = new char[_Dsize];
    memset(_Dest, 0, _Dsize);
    wcstombs(_Dest, _Source, _Dsize);
    string result = _Dest;
    delete[] _Dest;

    setlocale(LC_ALL, curLocale.c_str());

    return result;
}

wstring s2ws(const string &s)
{
    setlocale(LC_ALL, "chs");

    const char *_Source = s.c_str();
    size_t _Dsize = s.size() + 1;
    wchar_t *_Dest = new wchar_t[_Dsize];
    wmemset(_Dest, 0, _Dsize);
    mbstowcs(_Dest, _Source, _Dsize);
    wstring result = _Dest;
    delete[] _Dest;

    setlocale(LC_ALL, "C");

    return result;
}

void test()
{
    while (1)
    {
        ios::sync_with_stdio(false); // Linux gcc.
        locale::global(locale(""));
        wcout.imbue(locale(""));
        string s = "我去";
        wstring s1 = s2ws(s);
        wcout << s1;
    }
}
int main()
{
    test();
    return 0;
}