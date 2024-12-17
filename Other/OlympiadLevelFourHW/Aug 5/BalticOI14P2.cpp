#include <bits/stdc++.h>
using namespace std;
string s, str;
int len;
set<string> strSet;

int main()
{
    cin >> s;
    len = s.length();
    if (len % 2 == 0)
    {
        cout << "NOT POSSIBLE";
        return 0;
    }
    len--;
    len /= 2;
    str = s.substr(0, len);
    int cur = len, flag = 1;
    for (int i = 0; i < str.size(); i++)
    {
        while (cur < s.size() && str[i] != s[cur])
        {
            cur++;
            if (cur - i - len >= 2)
            {
                flag = 0;
                break;
            }
        }
        cur++;
    }
    if (flag)
        strSet.insert(str);
    cur = 0;
    flag = 1;
    str = s.substr(len + 1);
    for (int i = 0; i < str.size(); i++)
    {
        while (cur < s.size() && str[i] != s[cur])
        {
            cur++;
            if (cur - i >= 2)
            {
                flag = 0;
                break;
            }
        }
        cur++;
    }

    if (flag)
        strSet.insert(str);
    if (strSet.size() > 1)
    {
        cout << "NOT UNIQUE" << endl;
    }
    else if (strSet.size() == 1)
    {
        cout << *strSet.begin() << endl;
    }
    else
    {
        cout << "NOT POSSIBLE" << endl;
    }
}